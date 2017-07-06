/////////////////////////////////////////////////////////////////////////////
// Name:        MainDlg.cpp
// Purpose:     
// Author:      Jason Champion
// Modified by: 
// Created:     02/08/2006 11:45:51
// RCS-ID:      
// Copyright:   (c) 2006
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "MainDlg.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/aboutdlg.h"
#include "maindlg.h"
#include "samplemath.h"

IMPLEMENT_DYNAMIC_CLASS( MainDlg, wxDialog )

BEGIN_EVENT_TABLE( MainDlg, wxDialog )
    EVT_CLOSE( MainDlg::OnQuit )
    EVT_BUTTON( ID_BUTTON_SAMPLERATE, MainDlg::OnSamplerate )
    EVT_BUTTON( ID_BUTTON_SEMITONES, MainDlg::OnSemitones )
    EVT_BUTTON( ID_BUTTON_ABOUT, MainDlg::OnAbout )
END_EVENT_TABLE()

MainDlg::MainDlg()
{
}

MainDlg::~MainDlg()
{
}

MainDlg::MainDlg( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Create(parent, id, caption, pos, size, style);
}

/*!
 * MainDlg creator
 */
bool MainDlg::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    _txtSemitones = NULL;
    _txtStartSamplerate = NULL;
    _txtEndSamplerate = NULL;
    _btnSamplerate = NULL;
    _btnSemitones = NULL;

    SetExtraStyle(GetExtraStyle()|wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );
    wxInitAllImageHandlers();

    CreateControls();
	if( _icon.LoadFile(_("SRCalc.ico"), wxBITMAP_TYPE_ICO ))
	{
		SetIcon(_icon);
	}
    return true;
}

/*!
 * Control creation for MainDlg
 */
void MainDlg::CreateControls()
{
    MainDlg* itemDialog1 = this;

    wxFlexGridSizer* itemBoxSizer2 = new wxFlexGridSizer( 3, 3, 0, 0 );
    itemDialog1->SetSizer(itemBoxSizer2);

    wxStaticText* itemStaticText4 = new wxStaticText( itemDialog1, wxID_STATIC, _("Start Sample Rate/BPM:"), wxDefaultPosition, wxSize(160,30), 0 );
    itemBoxSizer2->Add(itemStaticText4, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 5);

    _txtStartSamplerate = new wxTextCtrl( itemDialog1, ID_START_SAMPLERATE, _T(""), wxDefaultPosition, wxSize(80, 30), 0 );
    itemBoxSizer2->Add(_txtStartSamplerate, 0, wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _btnAbout = new wxButton( itemDialog1, ID_BUTTON_ABOUT, _T("About"));
    itemBoxSizer2->Add(_btnAbout, 0, wxALIGN_CENTER_VERTICAL|wxALL, 3 );

    wxStaticText* itemStaticText5 = new wxStaticText( itemDialog1, wxID_STATIC, _("End Sample Rate/BPM:"), wxDefaultPosition, wxSize(160,30), 0 );
    itemBoxSizer2->Add(itemStaticText5, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 5);

    _txtEndSamplerate = new wxTextCtrl( itemDialog1, ID_END_SAMPLERATE, _T(""), wxDefaultPosition, wxSize(80,30), 0 );
    itemBoxSizer2->Add(_txtEndSamplerate, 0, wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _btnSamplerate = new wxButton( itemDialog1, ID_BUTTON_SAMPLERATE, _T("Calc"));
    itemBoxSizer2->Add(_btnSamplerate, 0, wxALIGN_CENTER_VERTICAL|wxALL, 3 );

    wxStaticText* itemStaticText6 = new wxStaticText( itemDialog1, wxID_STATIC, _("Semitone Shift:"), wxDefaultPosition, wxSize(160,30), 0 );
    itemBoxSizer2->Add(itemStaticText6, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 5);

    _txtSemitones = new wxTextCtrl( itemDialog1, ID_SEMITONES, _T(""), wxDefaultPosition, wxSize(80,30), 0 );
    itemBoxSizer2->Add(_txtSemitones, 0, wxALIGN_CENTER_VERTICAL|wxALL, 3);

    _btnSemitones = new wxButton( itemDialog1, ID_BUTTON_SEMITONES, _T("Calc"));
    itemBoxSizer2->Add(_btnSemitones, 0, wxALIGN_CENTER_VERTICAL|wxALL, 3 );
}

/*!
 * Should we show tooltips?
 */
bool MainDlg::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */
wxBitmap MainDlg::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
}

/*!
 * Get icon resources
 */
wxIcon MainDlg::GetIconResource( const wxString& name )
{
    // Icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
}

/**
 @brief  EVT_QUIT handler.
*/
void MainDlg::OnQuit(wxCloseEvent &event)
{
	Destroy();
}

void MainDlg::OnSamplerate(wxCommandEvent& event )
{
    int startsamplerate = atoi(_txtStartSamplerate->GetValue().mb_str());
    //int endsamplerate = atoi(_txtEndSamplerate->GetValue());
    double semitones = atof(_txtSemitones->GetValue().mb_str());
    if( startsamplerate == 0 || semitones == 0 ) return;

    double value = DoubleValueFromSemitoneShift( semitones, startsamplerate );

    _txtEndSamplerate->SetValue( wxString::Format( _("%.2f"), value ));
}

// If someone is editing the end sample rate, they obviously want to calculate semitones from SR difference.
void MainDlg::OnSemitones( wxCommandEvent& event )
{
    int startsamplerate = atoi(_txtStartSamplerate->GetValue().mb_str());
    double endsamplerate = atof(_txtEndSamplerate->GetValue().mb_str());
    //int semitones = atoi(_txtSemitones->GetValue());
    if( startsamplerate == 0 || endsamplerate == 0 ) return;

    double value = DoubleSemitoneShiftFromRatio( startsamplerate, endsamplerate );

    _txtSemitones->SetValue( wxString::Format( _("%.3f"), value ));
}

void MainDlg::OnAbout( wxCommandEvent& event )
{
	// Show about box.
    wxAboutDialogInfo info;
    info.SetName(_("Sample Rate and BPM Calculator"));
    info.SetVersion(_("1.02"));
    info.SetCopyright(_("(c) 2007-2017 Jason Champion"));
	info.AddDeveloper(_("Jason Champion"));
	info.SetIcon(_icon);
	info.SetLicense(_("Sample Rate and BPM Calculator is free software and may be distributed freely under the terms of the MIT license."));
	info.SetWebSite(_("https://github.com/Xangis/SampleRate"));
	info.SetDescription(_("Sample Rate and BPM Calculator uses the wxWidgets libraries."));

    wxAboutBox(info);
    event.Skip(false);
}

