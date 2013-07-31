#ifndef _WXSPECTRUM_H_
#define _WXSPECTRUM_H_

/*!
 * Includes
 */
#include "wx/image.h"
#include "maindlg.h"

/*!
 * wxApplication class declaration
 */
class wxApplication: public wxApp
{
    DECLARE_CLASS( wxApplication )
    DECLARE_EVENT_TABLE()

public:
    wxApplication();
    ~wxApplication();
    virtual bool OnInit();
    virtual int OnExit();

private:
	MainDlg* _MainDlg;
};

DECLARE_APP(wxApplication)

#endif
    // _WXSPECTRUM_H_
