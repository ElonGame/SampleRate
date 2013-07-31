#ifndef _MainDlg_H_
#define _MainDlg_H_

/*!
 * Includes
 */
#include "wx/wx.h"
#include "wx/spinctrl.h"

/*!
 * Forward declarations
 */
class wxSpinCtrl;

/*!
 * Control identifiers
 */
#define ID_MAINDIALOG 10000
#define SYMBOL_MAINDLG_STYLE wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX|wxMINIMIZE_BOX
#define SYMBOL_MAINDLG_TITLE _("Sample Rate and BPM Calculator")
#define SYMBOL_MAINDLG_IDNAME ID_MAINDIALOG
#define SYMBOL_MAINDLG_SIZE wxSize(360, 160)
#define SYMBOL_MAINDLG_POSITION wxDefaultPosition
#define ID_TEXT_FILENAME 10003
#define ID_START_SAMPLERATE 10004
#define ID_END_SAMPLERATE 10005
#define ID_SEMITONES 10006
#define ID_BUTTON_SAMPLERATE 10007
#define ID_BUTTON_SEMITONES 10008
#define ID_BUTTON_ABOUT 10009

/*!
 * Compatibility
 */
#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * MainDlg class declaration
 */
class MainDlg: public wxDialog
{
    DECLARE_DYNAMIC_CLASS( MainDlg )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    MainDlg();
    ~MainDlg();
    MainDlg( wxWindow* parent, wxWindowID id = SYMBOL_MAINDLG_IDNAME, const wxString& caption = SYMBOL_MAINDLG_TITLE, const wxPoint& pos = SYMBOL_MAINDLG_POSITION, const wxSize& size = SYMBOL_MAINDLG_SIZE, long style = SYMBOL_MAINDLG_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_MAINDLG_IDNAME, const wxString& caption = SYMBOL_MAINDLG_TITLE, const wxPoint& pos = SYMBOL_MAINDLG_POSITION, const wxSize& size = SYMBOL_MAINDLG_SIZE, long style = SYMBOL_MAINDLG_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

    void OnQuit(wxCloseEvent &event);
    void OnSamplerate( wxCommandEvent& event );
    void OnSemitones( wxCommandEvent& event );
    void OnAbout( wxCommandEvent& event );

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );

    /// Should we show tooltips?
    static bool ShowToolTips();

private:
    wxTextCtrl* _txtSemitones;
    wxTextCtrl* _txtStartSamplerate;
    wxTextCtrl* _txtEndSamplerate;
    wxButton* _btnSamplerate;
    wxButton* _btnSemitones;
    wxButton* _btnAbout;
	wxIcon _icon;
};

#endif
    // _MainDlg_H_
