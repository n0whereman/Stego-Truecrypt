/*
 Copyright (c) 2008 TrueCrypt Developers Association. All rights reserved.

 Governed by the TrueCrypt License 3.0 the full text of which is contained in
 the file License.txt included in TrueCrypt binary and source code distribution
 packages.
*/

#ifndef TC_HEADER_Main_Forms_EncoderVolumeSizePage
#define TC_HEADER_Main_Forms_EncoderVolumeSizePage

#include "Forms.h"

namespace TrueCrypt
{
	class EncoderVolumeSizePage : public EncoderVolumeSizePageBase
	{
	public:
		EncoderVolumeSizePage (wxPanel* parent);
		bool IsValid () { return true; }
		void SetPageText (const wxString &text) { }
		
		void setTmp(string a) {tmp = a;}
		const char* getTmp() {return tmp.c_str();}

		//shared_ptr <EncoderAlgorithm> GetEncoderAlgorithm () const;
		//bool IsValid () { return true; }
		//void SetPageText (const wxString &text) { }
		//void SetEncoderAlgorithm (shared_ptr <EncoderAlgorithm> algorithm);
		//void SetHash (shared_ptr <Hash> hash);

	protected:
		string tmp;
		//void OnScroll(wxScrollEvent& event);
		void SetStaticText ();
		//void OnBenchmarkButtonClick (wxCommandEvent& event);
		//void OnEncoderAlgorithmHyperlinkClick (wxHyperlinkEvent& event);
		//void OnEncoderAlgorithmSelected ();
		//void OnEncoderAlgorithmSelected (wxCommandEvent& event) { OnEncoderAlgorithmSelected(); }
		//void OnHashHyperlinkClick (wxHyperlinkEvent& event);
		//void OnTestButtonClick (wxCommandEvent& event);

		//EncoderAlgorithmList EncoderAlgorithms;
	};
}

#endif // TC_HEADER_Main_Forms_EncoderOptionsWizardPage
