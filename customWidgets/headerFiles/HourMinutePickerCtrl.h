//
// Created by fbi168 on 15/07/24.
//

#ifndef ACTIVITIES_REGISTER_HOURMINUTEPICKERCTRL_H
#define ACTIVITIES_REGISTER_HOURMINUTEPICKERCTRL_H
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "../../headerFiles/Time.h"

class HourMinutePickerCtrl : public wxPanel {
public:
    HourMinutePickerCtrl(wxWindow* parent, wxWindowID id = wxID_ANY);

    int GetHours() const;
    int GetMinutes() const;

private:
    void setUpSizers();

    wxSpinCtrl* hourSpinCtrl;
    wxSpinCtrl* minuteSpinCtrl;
};
#endif //ACTIVITIES_REGISTER_HOURMINUTEPICKERCTRL_H
