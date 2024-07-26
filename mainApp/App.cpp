//
// Created by fbi168 on 13/07/24.
//

#include "App.h"

wxIMPLEMENT_APP(App);
bool App::OnInit() {
    MainFrame *frame = new MainFrame("Activities Register");
    frame->SetClientSize(800, 600);
    frame->SetMinClientSize(wxSize(450, 350));
    frame->Center();
    frame->Show();
    return true;
}