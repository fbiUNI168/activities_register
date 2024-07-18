//
// Created by fbi168 on 15/07/24.
//

#include "../headerFiles/ActivityInput.h"
ActivityInput::ActivityInput(wxWindow *parent, wxWindowID id, const std::string &title, wxPoint position, wxSize size):
    wxDialog(parent, id, title, position, size){

    startTimePicker = new HourMinutePickerCtrl(this, wxID_ANY);

    endTimePicker = new HourMinutePickerCtrl(this, wxID_ANY);

    descriptionInput = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition,
                                      wxDefaultSize, wxTE_LEFT | wxTE_MULTILINE);

    addActivity = new wxButton(this, wxID_ANY, "Add");

    setUpSizers();

    addActivity->Bind(wxEVT_BUTTON, &ActivityInput::onButtonClick, this);
}

void ActivityInput::setUpSizers() {
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    sizer->Add(new wxStaticText(this, wxID_ANY, "Start time"),
               wxSizerFlags().Border(wxLEFT | wxTOP, 10));
    sizer->AddSpacer(10);
    sizer->Add(startTimePicker, wxSizerFlags().Border(wxLEFT, 10));
    sizer->AddSpacer(20);
    sizer->Add(new wxStaticText(this, wxID_ANY, "End time"),
               wxSizerFlags().Border(wxLEFT, 10));
    sizer->AddSpacer(10);
    sizer->Add(endTimePicker, wxSizerFlags().Border(wxLEFT, 10));
    sizer->AddSpacer(20);
    sizer->Add(descriptionInput,
               wxSizerFlags().Proportion(1).Expand().Border(wxALL, 10));
    sizer->AddSpacer(20);
    sizer->Add(addActivity, wxSizerFlags().Border(wxLEFT | wxBOTTOM, 10));

    SetSizer(sizer);
}

Activity ActivityInput::getActivity() const {
    std::string description = descriptionInput->GetValue().ToStdString();
    Time startTime(startTimePicker->GetHours(), startTimePicker->GetMinutes());
    Time endTime(endTimePicker->GetHours(), endTimePicker->GetMinutes());
    return Activity(description, activityDate, startTime, endTime);
}

void ActivityInput::setDate(int day, int month, int year) {
    activityDate.setDay(day);
    activityDate.setMonth(month);
    activityDate.setYear(year);
}

void ActivityInput::onButtonClick(const wxCommandEvent &evt) {
    wxDialog::EndModal(wxID_OK);
}