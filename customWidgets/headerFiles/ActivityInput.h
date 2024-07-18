//
// Created by fbi168 on 15/07/24.
//

#ifndef ACTIVITIES_REGISTER_ACTIVITYINPUT_H
#define ACTIVITIES_REGISTER_ACTIVITYINPUT_H
#include "../../headerFiles/Activity.h"
#include "HourMinutePickerCtrl.h"
#include <wx/timectrl.h>
#include <wx/wx.h>
class ActivityInput: public wxDialog {
public:
    ActivityInput(wxWindow *parent, wxWindowID id, const std::string& title, wxPoint position, wxSize size);

    Activity getActivity() const;

    void setDate(int day, int month, int year);
private:
    void setUpSizers();

    void onButtonClick(const wxCommandEvent& evt);

    wxTextCtrl *descriptionInput;
    HourMinutePickerCtrl *startTimePicker, *endTimePicker;
    wxButton *addActivity;

    Date activityDate;
};

#endif //ACTIVITIES_REGISTER_ACTIVITYINPUT_H
