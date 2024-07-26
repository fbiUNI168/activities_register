//
// Created by fbi168 on 13/07/24.
//

#ifndef ACTIVITIES_REGISTER_MAINFRAME_H
#define ACTIVITIES_REGISTER_MAINFRAME_H
#include "../headerFiles/Register.h"
#include "../customWidgets/headerFiles/ActivityInput.h"
#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/dataview.h>
#include <wx/font.h>
#include <exception>


class MainFrame: public wxFrame {
public:
    explicit MainFrame(const wxString& name);
private:
    void setWidgets();
    void bindHandler();
    void setSizers();

    void onKillDatePickerFocus(wxDateEvent& evt);
    void onCancDown(const wxKeyEvent &evt);
    void onAddButtonClick(const wxCommandEvent& evt);
    void onRemoveAllButtonClick(const wxCommandEvent &evt);
    void onWindowClosed(wxCloseEvent &evt);
    void onWindowOpen(const wxShowEvent &evt);

    void addActivity();
    void displayElements();
    Date wxDateTimetoDate();

    wxPanel *panel;
    wxStaticText *appTitle;
    wxDatePickerCtrl *datePicker;
    wxButton *addButton, *removeAllButton;
    wxDataViewCtrl *activitiesTable;
    wxDataViewListStore *model; //necessary to do the operation on the table
    ActivityInput *addActivitiesModal;

    Register activities;
};

#endif //ACTIVITIES_REGISTER_MAINFRAME_H
