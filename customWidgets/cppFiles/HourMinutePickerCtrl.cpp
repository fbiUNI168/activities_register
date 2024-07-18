#include "../headerFiles/HourMinutePickerCtrl.h"


HourMinutePickerCtrl::HourMinutePickerCtrl(wxWindow* parent, wxWindowID id)
        : wxPanel(parent, id)
{
    hourSpinCtrl = new wxSpinCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 23);
    minuteSpinCtrl = new wxSpinCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 59);

    setUpSizers();
}

void HourMinutePickerCtrl::setUpSizers() {
    wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);

    sizer->Add(new wxStaticText(this, wxID_ANY, "Hour:"),
               wxSizerFlags().Border(wxTOP, 5));
    sizer->AddSpacer(10);
    sizer->Add(hourSpinCtrl);
    sizer->AddSpacer(20);
    sizer->Add(new wxStaticText(this, wxID_ANY, "Minute:"),
               wxSizerFlags().Border(wxTOP, 5));
    sizer->AddSpacer(10);
    sizer->Add(minuteSpinCtrl);

    SetSizer(sizer);
}

int HourMinutePickerCtrl::GetHours() const
{
    return hourSpinCtrl->GetValue();
}

int HourMinutePickerCtrl::GetMinutes() const
{
    return minuteSpinCtrl->GetValue();
}