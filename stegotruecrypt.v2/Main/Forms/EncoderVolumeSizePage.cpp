/*
 Copyright (c) 2008 TrueCrypt Developers Association. All rights reserved.

 Governed by the TrueCrypt License 3.0 the full text of which is contained in
 the file License.txt included in TrueCrypt binary and source code distribution
 packages.
 */

#include "System.h"
//#include "Volume/EncoderTest.h"
//#include "Volume/Hash.h"
#include "Main/GraphicUserInterface.h"
#include "BenchmarkDialog.h"
#include "EncoderVolumeSizePage.h"
//#include "EncoderTestDialog.h"
//#include "Encoders/Encoder.h"


namespace TrueCrypt {

    EncoderVolumeSizePage::EncoderVolumeSizePage(wxPanel* parent)
    : EncoderVolumeSizePageBase(parent) {
        // HammingEncoder *encoder = new HammingEncoder(3);
        // manager->setDefaultEncoder(encoder);


        //Layout();


    }

    

    /*void EncoderVolumeSizePage::OnScroll(wxScrollEvent& event) {
        int position = Slider->GetValue();

        if (position == 0)
            staticText->SetLabel(_("Position 0"));
        else if (position == 1)
            staticText->SetLabel(_("Position 1"));
        else if (position == 2)
            staticText->SetLabel(_("Position 2"));
        else if (position == 3)
            staticText->SetLabel(_("Position 3"));
        else if (position == 4) {
            staticText->SetLabel(_("Position 4"));
            this->Refresh();
        } else if (position == 5) {
            staticText->SetLabel(_("Position 5"));
            this->Refresh();
        }



    }*/

  


}
