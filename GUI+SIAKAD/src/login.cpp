#include <wx/wx.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/msgdlg.h>
#include <wx/hyperlink.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>

class LoginFrame : public wxFrame
{
public:
    LoginFrame(const wxString& title);

private:
    wxTextCtrl* emailTextCtrl;
    wxTextCtrl* passwordTextCtrl;

    void OnLogin(wxCommandEvent& event);
    void OnForgotPassword(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(LoginFrame, wxFrame)
    EVT_BUTTON(wxID_ANY, LoginFrame::OnLogin)
    EVT_BUTTON(wxID_ANY, LoginFrame::OnForgotPassword)
wxEND_EVENT_TABLE()

LoginFrame::LoginFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(500, 300))
{

wxPanel* panel = new wxPanel(this, wxID_ANY);
wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

// Register PNG image handler
wxImage::AddHandler(new wxPNGHandler);

// Header Image
wxImage headerImage(wxT("welcome-header.png"), wxBITMAP_TYPE_PNG);
if (headerImage.IsOk())
{
    // Adjust the desired width and height for the image
    int imageWidth = 400;
    int imageHeight = 100;

    // Resize the image
    headerImage.Rescale(imageWidth, imageHeight);

    wxBitmap headerBitmap(headerImage);
    wxStaticBitmap* headerImageCtrl = new wxStaticBitmap(panel, wxID_ANY, headerBitmap);
    vbox->Add(headerImageCtrl, 0, wxALIGN_CENTER | wxALL, 10);
}
else
{
    wxMessageBox("Failed to load image file.", "Error", wxOK | wxICON_ERROR);
}
    // Welcome Text
    wxString welcomeText = "Selamat datang di sistem informasi akademik Institut Teknologi Komputer.\nSilakan gunakan surel berdomain 'dosen', 'students', atau 'tendik' untuk masuk.";
    wxStaticText* welcomeLabel = new wxStaticText(panel, wxID_ANY, welcomeText, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    vbox->Add(welcomeLabel, 0, wxALIGN_CENTER | wxALL, 10);

    // Email and Password Fields
    wxStaticText* emailLabel = new wxStaticText(panel, wxID_ANY, "Surel :");
    emailTextCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0);
    wxStaticText* passwordLabel = new wxStaticText(panel, wxID_ANY, "Kata Sandi :");
    passwordTextCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);

    vbox->Add(emailLabel, 0, wxALIGN_LEFT | wxALL, 5);
    vbox->Add(emailTextCtrl, 0, wxEXPAND | wxALL, 5);
    vbox->Add(passwordLabel, 0, wxALIGN_LEFT | wxALL, 5);
    vbox->Add(passwordTextCtrl, 0, wxEXPAND | wxALL, 5);

    // Login Button
    wxButton* loginButton = new wxButton(panel, wxID_ANY, "Log Masuk!");
    vbox->Add(loginButton, 0, wxALIGN_CENTER | wxALL, 5);

    // Forgot Password Button
    wxButton* forgotPasswordButton = new wxButton(panel, wxID_ANY, "Lupa Kata Sandi?");
    vbox->Add(forgotPasswordButton, 0, wxALIGN_CENTER | wxALL, 5);

    // Set the sizer
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

void LoginFrame::OnForgotPassword(wxCommandEvent& event)
{
    wxString message = "Jika Anda lupa detail log masuk Anda, silakan hubungi departemen atau DPTSI.";
    message += " Klik tombol di bawah untuk membuka situsnya.";

    wxMessageBox(message, "Pemulihan Kata Sandi", wxOK | wxICON_INFORMATION);

    // Open Google.com
    wxLaunchDefaultBrowser("https://www.google.com", wxBROWSER_NEW_WINDOW);

    Close();
}

class LoginApp : public wxApp
{
public:
    virtual bool OnInit();
};

bool LoginApp::OnInit()
{
    LoginFrame* frame = new LoginFrame("Login");
    frame->SetSize(wxSize(600, 400));
    frame->Show(true);
    return true;
}

wxIMPLEMENT_APP(LoginApp);
