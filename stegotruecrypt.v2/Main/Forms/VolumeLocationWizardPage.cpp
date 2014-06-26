/*
 Copyright (c) 2008 TrueCrypt Developers Association. All rights reserved.

 Governed by the TrueCrypt License 3.0 the full text of which is contained in
 the file License.txt included in TrueCrypt binary and source code distribution
 packages.
*/

#include "System.h"
#include "Main/GraphicUserInterface.h"
#include "Main/VolumeHistory.h"
#include "VolumeLocationWizardPage.h"

namespace TrueCrypt
{
	VolumeLocationWizardPage::VolumeLocationWizardPage (wxPanel* parent, VolumeHostType::Enum hostType, bool selectExisting)
		: VolumeLocationWizardPageBase (parent),
		SelectExisting (selectExisting)
	{
		switch (hostType)  //poskryvam, ktore netreba momo
		{
		case VolumeHostType::Device:
			SelectFileButton->Show (false);
			SelectStegoButton->Show (false);
			break;

		case VolumeHostType::StegoFS:
		     SelectFileButton->Show (false);
		     SelectDeviceButton->Show (false);
		     break;

		case VolumeHostType::File:
			SelectDeviceButton->Show (false);
			SelectStegoButton->Show (false);
			break;

		default:
			break;
		}

		Gui->PreferencesUpdatedEvent.Connect (EventConnector <VolumeLocationWizardPage> (this, &VolumeLocationWizardPage::OnPreferencesUpdated));
		VolumeHistory::ConnectComboBox (VolumePathComboBox);

		NoHistoryCheckBox->SetValue (!Gui->GetPreferences().SaveHistory);
	}

	VolumeLocationWizardPage::~VolumeLocationWizardPage ()
	{
		Gui->PreferencesUpdatedEvent.Disconnect (this);
		VolumeHistory::DisconnectComboBox (VolumePathComboBox);
	}

	void VolumeLocationWizardPage::OnNoHistoryCheckBoxClick (wxCommandEvent& event)
	{
		UserPreferences prefs = Gui->GetPreferences();
		prefs.SaveHistory = !event.IsChecked();
		Gui->SetPreferences (prefs);

		if (event.IsChecked())
		{
			try
			{
				VolumeHistory::Clear();
			}
			catch (exception &e) { Gui->ShowError (e); }
		}
	}
	
	void VolumeLocationWizardPage::OnPageChanging (bool forward)
	{
		if (forward)
		{
			VolumePath path = GetVolumePath();
			if (!path.IsEmpty())
				VolumeHistory::Add (path);
		}
	}

	void VolumeLocationWizardPage::OnPreferencesUpdated (EventArgs &args)
	{
		NoHistoryCheckBox->SetValue (!Gui->GetPreferences().SaveHistory);
	}

	void VolumeLocationWizardPage::OnSelectFileButtonClick (wxCommandEvent& event)
	{
		FilePath path = Gui->SelectVolumeFile (this, !SelectExisting);

		if (!path.IsEmpty())
			SetVolumePath (path);
	}

	void VolumeLocationWizardPage::OnSelectDeviceButtonClick (wxCommandEvent& event)
	{
		DevicePath path = Gui->SelectDevice (this);

		if (!path.IsEmpty())
			SetVolumePath (path);
	}

	void VolumeLocationWizardPage::OnSelectStegoButtonClick (wxCommandEvent& event)
	{
		StegoPath path = Gui->SelectStegoDirectory (this);

		if (!path.IsEmpty())
			SetVolumePath (path);
	}

	void VolumeLocationWizardPage::SetVolumePath (const VolumePath &path)
	{
		VolumePathComboBox->SetValue (wstring (path));
		PageUpdatedEvent.Raise();
	}
}
