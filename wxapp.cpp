/////////////////////////////////////////////////////////////////////////////
// Name:        wxapp.cpp
// Purpose:     
// Author:      Jason Champion
// Modified by: 
// Created:     02/08/2006 11:42:44
// RCS-ID:      
// Copyright:   (c) 2006
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#include "wx/wx.h"
#include "wxapp.h"

/*!
 * Application instance implementation
 */
IMPLEMENT_APP( wxApplication )

/*!
 * wxApplication type definition
 */
IMPLEMENT_CLASS( wxApplication, wxApp )

/*!
 * wxApplication event table definition
 */
BEGIN_EVENT_TABLE( wxApplication, wxApp )
END_EVENT_TABLE()

/*!
 * Initialisation for wxApplication
 */
bool wxApplication::OnInit()
{
    // Remove the comment markers above and below this block
    // to make permanent changes to the code.

#if wxUSE_XPM
    wxImage::AddHandler(new wxXPMHandler);
#endif
#if wxUSE_LIBPNG
    wxImage::AddHandler(new wxPNGHandler);
#endif
#if wxUSE_LIBJPEG
    wxImage::AddHandler(new wxJPEGHandler);
#endif
#if wxUSE_GIF
    wxImage::AddHandler(new wxGIFHandler);
#endif
    _MainDlg = new MainDlg(NULL);
    _MainDlg->Show(true);

    return true;
}

/*!
 * Cleanup for wxApplication
 */
int wxApplication::OnExit()
{
    return wxApp::OnExit();
}


wxApplication::wxApplication()
{
}

wxApplication::~wxApplication()
{
}
