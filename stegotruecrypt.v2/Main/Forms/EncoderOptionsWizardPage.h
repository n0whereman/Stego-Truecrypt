/*
 Copyright (c) 2008 TrueCrypt Developers Association. All rights reserved.

 Governed by the TrueCrypt License 3.0 the full text of which is contained in
 the file License.txt included in TrueCrypt binary and source code distribution
 packages.
*/

#ifndef TC_HEADER_Main_Forms_EncoderOptionsWizardPage
#define TC_HEADER_Main_Forms_EncoderOptionsWizardPage

#include "Volume/EncoderAlgorithm.h"
#include "Forms.h"
#include "FileManagement/CarrierFilesManager.h"

namespace TrueCrypt
{
	class EncoderOptionsWizardPage : public EncoderOptionsWizardPageBase
	{
	public:
		EncoderOptionsWizardPage (wxPanel* parent,shared_ptr <CarrierFilesManager> manager);
        bool IsValid (); //momo VELKE TODO: MY musi najprv prerobit stegodisk, getcapacity mozme pouzivat avsak predtym, uz musi byt encoder aplikovany, tu uvolnujeme NEXT buttonik 
        unsigned int position;
		void SetPageText (const wxString &text) { };
		shared_ptr <Encoder> GetEncoder () const;
		shared_ptr <Encoder> GetParameterizedEncoder () const;
		void OnEncoderAlgorithmSelected ();
		void OnEncoderAlgorithmSelected (wxCommandEvent& event) { OnEncoderAlgorithmSelected(); };
		void OnLsbAlgorithmSelected (wxCommandEvent& event) { OnLsbAlgorithmSelected (); };
		void OnLsbAlgorithmSelected (shared_ptr<Encoder> LsbEncoder);
		void OnLsbAlgorithmSelected ();
		void OnHammingAlgorithmSelected (shared_ptr<Encoder> HammingEncoder, int position);
		void OnScroll(wxScrollEvent& event);
		void SetEncoder (shared_ptr <Encoder> algorithm);
		void SetMaxVolumeSize (uint64 size) { MaxVolumeSize = size; MaxVolumeSizeValid = true; }
		void SetMinVolumeSize (uint64 size) { MinVolumeSize = size; }
	protected:
		   typedef list < shared_ptr <Encoder> > EncoderAlgorithmList;
		   shared_ptr <CarrierFilesManager> manager;            
           EncoderAlgorithmList EncoderAlgorithms;
           list <string> BlockSizes;
           shared_ptr <Encoder> ea;
           uint64 MaxVolumeSize;
           uint64 MinVolumeSize;
           bool MaxVolumeSizeValid;
			uint32 SectorSize;
		
	};
}

#endif // TC_HEADER_Main_Forms_EncoderOptionsWizardPage
