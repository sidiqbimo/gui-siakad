#include <wx/wx.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/msgdlg.h>
#include <wx/hyperlink.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/grid.h>

// Forward declaration of LoginFrame class
class LoginFrame;

// Define TranscriptFrame class
class TranscriptFrame : public wxFrame
{
public:
    TranscriptFrame(wxWindow* parent)
        : wxFrame(parent, wxID_ANY, "Riwayat IP", wxDefaultPosition, wxSize(600, 400))
    {
        wxStaticText* gpaText = new wxStaticText(this, wxID_ANY, "Indeks Prestasi Saya\n");
        wxStaticText* semester1Text = new wxStaticText(this, wxID_ANY, "Semester 1 : 3.33");
        wxStaticText* semester2Text = new wxStaticText(this, wxID_ANY, "Semester 2 : 3.56");
        
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        sizer->Add(gpaText, 0, wxALL, 10);
        sizer->Add(semester1Text, 0, wxLEFT | wxRIGHT, 10);
        sizer->Add(semester2Text, 0, wxLEFT | wxRIGHT, 10);
        
        SetSizerAndFit(sizer);
    }
};

//JADWAL
class ScheduleFrame : public wxFrame
{
public:
    ScheduleFrame(wxWindow* parent)
        : wxFrame(parent, wxID_ANY, "Jadwal Kuliah", wxDefaultPosition, wxSize(800, 600))
    {
        wxGrid* grid = new wxGrid(this, wxID_ANY);

        // Set the number of rows and columns
        grid->CreateGrid(10, 4);

        // Set the column labels
        grid->SetColLabelValue(0, "Waktu");
        grid->SetColLabelValue(1, "Mata Kuliah");
        grid->SetColLabelValue(2, "Dosen");
        grid->SetColLabelValue(3, "Ruang");

        // Set the row labels
        for (int i = 0; i < 10; i++)
            grid->SetRowLabelValue(i, wxString::Format("%d", i + 1));

        // Set the cell values
        grid->SetCellValue(0, 0, "Sen, 08:00 - 09:40");
        grid->SetCellValue(0, 1, "Kalkulus");
        grid->SetCellValue(0, 2, "Herman Darmansyah");
        grid->SetCellValue(0, 3, "113");

        grid->SetCellValue(1, 0, "Sel, 08:00 - 09:40");
        grid->SetCellValue(1, 1, "Pemrograman Web");
        grid->SetCellValue(1, 2, "Herman Darmansyah");
        grid->SetCellValue(1, 3, "114");


        // Set the grid to automatically size the columns to fit the content
        grid->AutoSizeColumns();
    }
};



// Define StudentMainMenuFrame class
class StudentMainMenuFrame : public wxFrame
{
public:
    StudentMainMenuFrame(const wxString& title);

private:
    void OnButton1Clicked(wxCommandEvent& event);
    void OnButton2Clicked(wxCommandEvent& event);
    void OnButton3Clicked(wxCommandEvent& event);
    void OnButton4Clicked(wxCommandEvent& event);
    void OnButton5Clicked(wxCommandEvent& event);
    void OnButton6Clicked(wxCommandEvent& event);

    
    wxPanel* CreateButtonWithIcon(wxWindow* parent, wxWindowID id, const wxString& label, const wxString& iconFile);
};

// Define LoginFrame class
class LoginFrame : public wxFrame
{
public:
    LoginFrame(const wxString& title);

private:
    wxTextCtrl* emailTextCtrl;
    wxTextCtrl* passwordTextCtrl;

    void OnLogin(wxCommandEvent& event);
    void OnForgotPassword(wxHyperlinkEvent& event);

    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(LoginFrame, wxFrame)
    EVT_BUTTON(wxID_ANY, LoginFrame::OnLogin)
    EVT_HYPERLINK(wxID_ANY, LoginFrame::OnForgotPassword)
wxEND_EVENT_TABLE()


LoginFrame::LoginFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(450, 500))
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
    vbox->Add(welcomeLabel, 0, wxALIGN_CENTER | wxALL, .10);

// Email Text
wxStaticText* emailLabel = new wxStaticText(panel, wxID_ANY, "Email:", wxDefaultPosition, wxDefaultSize);
emailTextCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);

// Password Text
wxStaticText* passwordLabel = new wxStaticText(panel, wxID_ANY, "Password:", wxDefaultPosition, wxDefaultSize);
passwordTextCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);

// Login Button
wxButton* loginButton = new wxButton(panel, wxID_ANY, "Login");
loginButton->SetDefault();

// Forgot Password Link
wxHyperlinkCtrl* forgotPasswordLink = new wxHyperlinkCtrl(panel, wxID_ANY, "Lupa Kata Sandi?", "", wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE);

// Add elements to sizer
vbox->Add(emailLabel, 0, wxALIGN_CENTER | wxALL, 5);
vbox->Add(emailTextCtrl, 0, wxEXPAND | wxALL, 5);
vbox->Add(passwordLabel, 0, wxALIGN_CENTER | wxALL, 5);
vbox->Add(passwordTextCtrl, 0, wxEXPAND | wxALL, 5);
vbox->Add(loginButton, 0, wxALIGN_CENTER | wxALL, 5);
vbox->Add(forgotPasswordLink, 0, wxALIGN_CENTER | wxALL, 5);

panel->SetSizerAndFit(vbox);
}

// Implement the member functions of StudentMainMenuFrame

StudentMainMenuFrame::StudentMainMenuFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 750))
{
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    // Register PNG image handler
    wxImage::AddHandler(new wxPNGHandler);

    // Create a grid sizer with 2 columns
    wxGridSizer* gridSizer = new wxGridSizer(2);

    // Button 1
    wxPanel* button1 = CreateButtonWithIcon(panel, wxID_ANY, "Indeks Prestasi", "1.png");
    gridSizer->Add(button1);
    button1->Bind(wxEVT_BUTTON, &StudentMainMenuFrame::OnButton1Clicked, this);

    // Button 2
    wxPanel* button2 = CreateButtonWithIcon(panel, wxID_ANY, "Jadwal Kuliah", "2.png");
    gridSizer->Add(button2);
    button2->Bind(wxEVT_BUTTON, &StudentMainMenuFrame::OnButton2Clicked, this);

    // Button 3
    wxPanel* button3 = CreateButtonWithIcon(panel, wxID_ANY, "Pengisian IPD", "3.png");
    gridSizer->Add(button3);

    // Button 4
    wxPanel* button4 = CreateButtonWithIcon(panel, wxID_ANY, "Ajukan Surat", "4.png");
    gridSizer->Add(button4);

    // Button 5
    wxPanel* button5 = CreateButtonWithIcon(panel, wxID_ANY, "Manajemen UKT", "5.png");
    gridSizer->Add(button5);

    // Button 6
    wxPanel* button6 = CreateButtonWithIcon(panel, wxID_ANY, "Log Keluar", "6.png");
    gridSizer->Add(button6);

    // Set sizer for the panel
    panel->SetSizer(gridSizer);
}


void StudentMainMenuFrame::OnButton1Clicked(wxCommandEvent& event)
{
    TranscriptFrame* transcriptFrame = new TranscriptFrame(this);
    transcriptFrame->Show();
}

void StudentMainMenuFrame::OnButton2Clicked(wxCommandEvent& event)
{
    ScheduleFrame* scheduleFrame = new ScheduleFrame(this);
    scheduleFrame->Show();
}

void StudentMainMenuFrame::OnButton3Clicked(wxCommandEvent& event)
{
    // Handle button 3 click event (Pengisian IPD)
    wxMessageBox("Pengisian IPD clicked!", "Info", wxOK | wxICON_INFORMATION);
}

void StudentMainMenuFrame::OnButton4Clicked(wxCommandEvent& event)
{
    // Handle button 4 click event (Ajukan Surat)
    wxMessageBox("Ajukan Surat clicked!", "Info", wxOK | wxICON_INFORMATION);
}

void StudentMainMenuFrame::OnButton5Clicked(wxCommandEvent& event)
{
    // Handle button 5 click event (Manajemen UKT)
    wxMessageBox("Manajemen UKT clicked!", "Info", wxOK | wxICON_INFORMATION);
}

void StudentMainMenuFrame::OnButton6Clicked(wxCommandEvent& event)
{
    // Handle button 6 click event (Log Keluar)
    LoginFrame* loginFrame = new LoginFrame("Login");
    loginFrame->Show();

    Close();
}

// Implement the member functions of LoginFrame

void LoginFrame::OnLogin(wxCommandEvent& event)
{
    wxString email = emailTextCtrl->GetValue();
    wxString password = passwordTextCtrl->GetValue();

    // Perform login validation here
    // If the login is successful, open the TranscriptFrame
    // If the login is unsuccessful, display an error message

    // For demonstration purposes, assume the login is successful
    wxMessageBox("Login successful!", "Success", wxOK | wxICON_INFORMATION);
    
    // Close the LoginFrame
    Close();
    
    // Create and show the StudentMainMenuFrame
    StudentMainMenuFrame* mainMenuFrame = new StudentMainMenuFrame("Menu Mahasiswa");
    mainMenuFrame->Show();
}

void LoginFrame::OnForgotPassword(wxHyperlinkEvent& event)
{
    wxString message = "Jika Anda lupa kata sandi Anda, silakan hubungi DPTSI atau klik tombol di bawah.";
    int response = wxMessageBox(message, "Forgot Password", wxOK | wxICON_INFORMATION);
    
    if (response == wxOK)
    {
        wxString url = "https://www.its.ac.id/dptsi/id/kontak-kami-2/";
        wxLaunchDefaultBrowser(url);
    }
}

wxPanel* StudentMainMenuFrame::CreateButtonWithIcon(wxWindow* parent, wxWindowID id, const wxString& label, const wxString& iconFile)
{
    wxPanel* panel = new wxPanel(parent, id);
    wxButton* button = new wxButton(panel, id, label);

    wxImage image(iconFile, wxBITMAP_TYPE_PNG);
    int newWidth = 64;
    int newHeight = image.GetHeight() * newWidth / image.GetWidth();
    image.Rescale(newWidth, newHeight);

    wxBitmap bitmap(iconFile, wxBITMAP_TYPE_PNG);
    wxBitmapButton* bitmapButton = new wxBitmapButton(panel, id, bitmap);
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(bitmapButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);
    sizer->Add(button, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);
    panel->SetSizerAndFit(sizer);
    return panel;
}



// Implement the wxWidgets app

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

bool MyApp::OnInit()
{
    // Create and show the LoginFrame
    LoginFrame* loginFrame = new LoginFrame("Login");
    loginFrame->Show();
    return true;
}

wxIMPLEMENT_APP(MyApp);
