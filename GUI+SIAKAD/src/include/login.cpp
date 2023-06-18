#include <wx/wx.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/msgdlg.h>

class LoginFrame : public wxFrame
{
public:
    LoginFrame(const wxString& title);

private:
    wxTextCtrl* emailTextCtrl;
    wxTextCtrl* passwordTextCtrl;

    void OnLogin(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(LoginFrame, wxFrame)
    EVT_BUTTON(wxID_ANY, LoginFrame::OnLogin)
wxEND_EVENT_TABLE()

LoginFrame::LoginFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(300, 200))
{
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    wxStaticText* emailLabel = new wxStaticText(panel, wxID_ANY, "Email:");
    emailTextCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0);
    wxStaticText* passwordLabel = new wxStaticText(panel, wxID_ANY, "Password:");
    passwordTextCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);

    vbox->Add(emailLabel, 0, wxALIGN_LEFT | wxALL, 5);
    vbox->Add(emailTextCtrl, 0, wxEXPAND | wxALL, 5);
    vbox->Add(passwordLabel, 0, wxALIGN_LEFT | wxALL, 5);
    vbox->Add(passwordTextCtrl, 0, wxEXPAND | wxALL, 5);

    wxButton* loginButton = new wxButton(panel, wxID_ANY, "Login");
    vbox->Add(loginButton, 0, wxALIGN_CENTER | wxALL, 5);

    panel->SetSizer(vbox);

    Centre();

    loginButton->SetDefault();
}

void LoginFrame::OnLogin(wxCommandEvent& event)
{
    wxString email = emailTextCtrl->GetValue();

    if (email.Contains("students"))
    {
        wxMessageBox("Logged in as Student", "Student", wxOK | wxICON_INFORMATION);
        Close();
    }
    else if (email.Contains("tendik"))
    {
        wxMessageBox("Logged in as Tendik", "Tendik", wxOK | wxICON_INFORMATION);
        Close();
    }
    else if (email.Contains("dosen"))
    {
        wxMessageBox("Logged in as Dosen", "Dosen", wxOK | wxICON_INFORMATION);
        Close();
    }
    else
    {
        wxMessageBox("Login credentials are incorrect!", "Error", wxOK | wxICON_ERROR);
    }
}

class LoginApp : public wxApp
{
public:
    virtual bool OnInit();
};

bool LoginApp::OnInit()
{
    LoginFrame* frame = new LoginFrame("Login");
    frame->Show(true);
    return true;
}

wxIMPLEMENT_APP(LoginApp);
