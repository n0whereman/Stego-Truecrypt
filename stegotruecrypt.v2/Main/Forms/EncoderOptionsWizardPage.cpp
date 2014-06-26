/*
 Copyright (c) 2008 TrueCrypt Developers Association. All rights reserved.

 Governed by the TrueCrypt License 3.0 the full text of which is contained in
 the file License.txt included in TrueCrypt binary and source code distribution
 packages.




 virtual storage vytvorit tam kde managera....setnut
*/

#include "System.h"
#include "Volume/EncryptionTest.h"
#include "Volume/Hash.h"
#include "Main/GraphicUserInterface.h"
#include "EncoderOptionsWizardPage.h"
#include "EncryptionTestDialog.h"

namespace TrueCrypt
{
	EncoderOptionsWizardPage::EncoderOptionsWizardPage (wxPanel* parent, shared_ptr<CarrierFilesManager> _manager)
		: EncoderOptionsWizardPageBase (parent)
	{
		this->manager = _manager;
		EncoderAlgorithms = EncoderAlgorithm::GetAvailableAlgorithms();
		wstring str;
		string s; 

		for (unsigned int i=LsbEncoder::getBlockSizeMin(); i<=LsbEncoder::getBlockSizeMax(); i <<= 1)
        	LsbBlockSize->Append (std::to_wstring(i));
       
		foreach (shared_ptr <Encoder> ea, EncoderAlgorithms)
		{
			s = ea->getNameInstance();
		    wstring ws(s.size(), L' '); 
		    ws.resize(mbstowcs(&ws[0], s.c_str(), s.size()));                   
			
			EncoderAlgorithmChoice->Append (ws, ea.get()); 
		}
		EncoderAlgorithmChoice->Select (0);
		LsbBlockSize->Select (0);
		OnEncoderAlgorithmSelected ();
		

	}

	shared_ptr <Encoder> EncoderOptionsWizardPage::GetEncoder () const
	{
		return Gui->GetSelectedData <Encoder> (EncoderAlgorithmChoice)->getNewInstance();
	}

	shared_ptr <Encoder> EncoderOptionsWizardPage::GetParameterizedEncoder () const
	{
		return ea;
	}


	void EncoderOptionsWizardPage::OnEncoderAlgorithmSelected ()
	{
		FreezeScope freeze (this);

		ea = GetEncoder();

		if (typeid (*ea) == typeid (HammingEncoder))  {            
            EncoderAlgorithmStaticText->SetLabel (LangString["HAMMING_HELP"]);
            Slider->Show();
            LsbBlockSize->Hide();  
            EncoderMaxSize->Show();          
            OnHammingAlgorithmSelected(ea,3);
		}     
		    
	    if (typeid (*ea) == typeid (LsbEncoder))   {
	    	EncoderAlgorithmStaticText->SetLabel (LangString["LSB_HELP"]);	
			Slider->Hide();
			EncoderMaxSize->Hide();
			LsbBlockSize->Show();
			OnLsbAlgorithmSelected(ea);
	    }    		
		
		Layout();
	}


    void EncoderOptionsWizardPage::OnLsbAlgorithmSelected ()
	{
		FreezeScope freeze (this);
		OnLsbAlgorithmSelected (ea);		
		//Layout();
	}

	 void EncoderOptionsWizardPage::OnLsbAlgorithmSelected (shared_ptr<Encoder> LsbEncoder)
	{
		FreezeScope freeze (this);
		unsigned int value = LsbBlockSize->GetSelection();
		wxString wx_string = LsbBlockSize->GetString(value);
		string stlstring = std::string(wx_string.mb_str());
        LsbEncoder->setArgByName("blockSize",stlstring);
        manager->setEncoder(LsbEncoder);
		manager->applyEncoder();			
		//Layout();
	}


	 void EncoderOptionsWizardPage::OnHammingAlgorithmSelected (shared_ptr<Encoder> HammingEncoder, int position)
	{
		FreezeScope freeze (this);
		std::string Parity_Bits = std::to_string(position);
		HammingEncoder->setArgByName("paritybits",Parity_Bits.c_str());
		manager->setEncoder(HammingEncoder);
		manager->applyEncoder();		
		wxString mystring;
		mystring << manager->getCapacity();
        //_("Maximal usable capacity is")
		EncoderMaxSize->SetLabel(_("Maximal usable capacity is ") + mystring + _(" bits."));
	}


   
	void EncoderOptionsWizardPage::SetEncoder (shared_ptr <Encoder> algorithm)
	{
		if (algorithm)
		{
			string s = algorithm->getNameInstance().c_str();
		    wstring ws(s.size(), L' '); 
		    ws.resize(mbstowcs(&ws[0], s.c_str(), s.size()));  
			EncoderAlgorithmChoice->SetStringSelection (ws);
			OnEncoderAlgorithmSelected ();
		}
	}

	bool  EncoderOptionsWizardPage::IsValid ()
	{
		if (Validate())
		{
			try
			{
				if (manager->getCapacity() >= MinVolumeSize )
					return true;
			}
			catch (...) { }
		}
		return false;
	}

	void EncoderOptionsWizardPage::OnScroll(wxScrollEvent& event) {
        
        int position = Slider->GetValue();
        
        if (position == 0) {            
            OnHammingAlgorithmSelected(ea,3);
        }
        else if (position == 1) {
            OnHammingAlgorithmSelected(ea,4);
        }
        else if (position == 2) {
            OnHammingAlgorithmSelected(ea,5);
        }
        else if (position == 3) {
            OnHammingAlgorithmSelected(ea,6);
        }
        else if (position == 4) {
            OnHammingAlgorithmSelected(ea,7);
        } 
        else if (position == 5) {
            OnHammingAlgorithmSelected(ea,8);
        } 
        Layout();
    }


	

	
	
}
