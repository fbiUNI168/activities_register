//
// Created by fbi168 on 13/07/24.
//

#include "MainFrame.h"

MainFrame::MainFrame(const wxString &name): wxFrame(nullptr, wxID_ANY, name) {
    setWidgets();
    setSizers();
    bindHandler();
}

void MainFrame::setWidgets() {
    //TODO try to add different font to the code
    wxFont headlineFont(wxFontInfo(wxSize(0, 36)).Bold());
    wxFont mainFont(wxFontInfo(wxSize(0, 24)));

    panel = new wxPanel(this);

    appTitle = new wxStaticText(panel, wxID_ANY, "My activitiesTable register");

    searchButton = new wxButton(panel, wxID_ANY, "Search");

    datePicker = new wxDatePickerCtrl(panel, wxID_ANY, wxDateTime::Now());

    model = new wxDataViewListStore();
    model->AppendColumn("Start");
    model->AppendColumn("End");
    model->AppendColumn("Description");

    activitiesTable = new wxDataViewCtrl(panel, wxID_ANY);
    activitiesTable->AssociateModel(model);
    model->DecRef();
    activitiesTable->AppendTextColumn("Start", 0, wxDATAVIEW_CELL_INERT, 100, wxALIGN_LEFT);
    activitiesTable->AppendTextColumn("End", 1, wxDATAVIEW_CELL_INERT, 100, wxALIGN_LEFT);
    activitiesTable->AppendTextColumn("Description", 2, wxDATAVIEW_CELL_INERT, 300, wxALIGN_LEFT);
    activitiesTable->GetColumn(1)->SetSortOrder(true);

    addButton = new wxButton(panel, wxID_ANY, "Add");

    removeAllButton = new wxButton(panel, wxID_ANY, "Remove All");

    addActivitiesModal = new ActivityInput(panel, wxID_ANY, "Add an activity", wxDefaultPosition, wxSize(500, 500));
}

void MainFrame::setSizers() {
    wxBoxSizer *elementsSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *searchActivitySizer = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *operationsSizer = new wxBoxSizer(wxHORIZONTAL);

    elementsSizer->AddSpacer(30);
    elementsSizer->Add(appTitle, wxSizerFlags().Center());
    elementsSizer->AddSpacer(10);

    searchActivitySizer->Add(datePicker);
    searchActivitySizer->AddSpacer(30);
    searchActivitySizer->Add(searchButton);
    elementsSizer->Add(searchActivitySizer, wxSizerFlags().Center());
    elementsSizer->AddSpacer(30);

    elementsSizer->Add(activitiesTable,
                       wxSizerFlags().Proportion(1).Expand().Border(wxLEFT | wxRIGHT, 10));
    elementsSizer->AddSpacer(5);

    operationsSizer->Add(addButton);
    operationsSizer->AddSpacer(20);
    operationsSizer->Add(removeAllButton);
    elementsSizer->Add(operationsSizer, wxSizerFlags().Border(wxLEFT | wxBOTTOM, 20));

    panel->SetSizer(elementsSizer);
    elementsSizer->SetSizeHints(this);
}

void MainFrame::bindHandler() {
    searchButton->Bind(wxEVT_BUTTON, &MainFrame::onSearchButtonClick, this);
    activitiesTable->Bind(wxEVT_KEY_DOWN, &MainFrame::onCancDown, this);
    addButton->Bind(wxEVT_BUTTON, &MainFrame::onAddButtonClick, this);
    removeAllButton->Bind(wxEVT_BUTTON, &MainFrame::onRemoveAllButtonClick, this);
}

//TODO optimize this function in order to avoid clear the table in case that no new date has been selected
void MainFrame::onSearchButtonClick(const wxCommandEvent &evt) {
    Date selectedDate = wxDateTimetoDate();
    std::vector<Activity> activityVector = activities.getActivitiesForDate(selectedDate.getParsedDate());

    model->DeleteAllItems();
    for(auto& activity: activityVector){
        wxVector<wxVariant> tableItem;
        tableItem.push_back(wxVariant(activity.getStartTime().toString()));
        tableItem.push_back(wxVariant(activity.getEndTime().toString()));
        tableItem.push_back(wxVariant(activity.getDescription()));

        model->AppendItem(tableItem);
    }
}

void MainFrame::onCancDown(const wxKeyEvent &evt) {
    if(evt.GetKeyCode() == WXK_DELETE){
        int index = model->GetRow(activitiesTable->GetSelection());
        Date selectedDate = wxDateTimetoDate();
        activities.deleteActivity(selectedDate.getParsedDate() ,index);
        model->DeleteItem(index);
    }
}

void MainFrame::onAddButtonClick(const wxCommandEvent &evt) {
    Date selectedDate = wxDateTimetoDate();
    int modalStatus = addActivitiesModal->ShowModal();
    addActivitiesModal->setDate(selectedDate.getDay(), selectedDate.getMonth(), selectedDate.getYear());

    if(modalStatus == wxID_OK)
        addActivity();
}

void MainFrame::onRemoveAllButtonClick(const wxCommandEvent &evt) {
    wxMessageDialog *warningMessage;
    if(model->GetItemCount() == 0) {
        warningMessage = new wxMessageDialog(panel, "So far you haven't added activities",
                                             "NO ACTIVITIES TO DELETE");
    }else{
        warningMessage = new wxMessageDialog(panel,
                                             "Are you sure to delete all the activities?",
                                             "DELETE ALL THE ACTIVITIES",
                                             wxYES_NO | wxCENTER);
    }
    int result = warningMessage->ShowModal();
    if(result == wxID_YES){
        Date selectedDate = wxDateTimetoDate();
        activities.deleteActivities(selectedDate.getParsedDate());
        model->DeleteAllItems();
    }
}

void MainFrame::addActivity() {
    try{
        Activity activity = addActivitiesModal->getActivity();
        activities.addActivity(activity);

        wxVector<wxVariant> tableItem;
        tableItem.push_back(wxVariant(activity.getStartTime().toString()));
        tableItem.push_back(wxVariant(activity.getEndTime().toString()));
        tableItem.push_back(wxVariant(activity.getDescription()));

        model->AppendItem(tableItem);
    }catch(std::invalid_argument& exc){
        wxMessageBox(exc.what());
    }catch(std::out_of_range& exc){
        wxMessageBox(exc.what());
    }
}

Date MainFrame::wxDateTimetoDate() {
    wxDateTime date = datePicker->GetValue();
    int month = static_cast<int>(date.GetMonth()) + 1;
    return Date(date.GetDay(), month, date.GetYear());
}