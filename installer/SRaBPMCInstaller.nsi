;Include Modern UI

  !include "MUI2.nsh"
  !include "FileAssociation.nsh"

Name "Sample Rate and BPM Calculator 1.01"
OutFile "SampleRateAndBPMCalculator1.01Setup.exe"
InstallDir "$PROGRAMFILES\Zeta Centauri\Sample Rate and BPM Calculator"
InstallDirRegKey HKLM "Software\Sample Rate and BPM Calculator" "Install_Dir"
RequestExecutionLevel admin
!define MUI_ICON "SRCalc.ico"
!define MUI_UNICON "SRCalc.ico"

;Version Information

  VIProductVersion "1.0.1.0"
  VIAddVersionKey /LANG=${LANG_ENGLISH} "ProductName" "Sample Rate and BPM Calculator"
  VIAddVersionKey /LANG=${LANG_ENGLISH} "CompanyName" "Zeta Centauri"
  VIAddVersionKey /LANG=${LANG_ENGLISH} "LegalCopyright" "Copyright 2007-2012 Zeta Centauri"
  VIAddVersionKey /LANG=${LANG_ENGLISH} "FileDescription" "Sample Rate and BPM Calculator Installer"
  VIAddVersionKey /LANG=${LANG_ENGLISH} "FileVersion" "1.0.1.0"
  VIAddVersionKey /LANG=${LANG_ENGLISH} "ProductVersion" "1.0.1.0"

;Interface Settings

  !define MUI_ABORTWARNING

;Pages

  !insertmacro MUI_PAGE_LICENSE "License.txt"
;  !insertmacro MUI_PAGE_DIRECTORY
  !insertmacro MUI_PAGE_INSTFILES
      !define MUI_FINISHPAGE_NOAUTOCLOSE
      !define MUI_FINISHPAGE_RUN
      !define MUI_FINISHPAGE_RUN_CHECKED
      !define MUI_FINISHPAGE_RUN_TEXT "Launch Sample Rate and BPM Calculator"
      !define MUI_FINISHPAGE_RUN_FUNCTION "LaunchProgram"
      !define MUI_FINISHPAGE_SHOWREADME ""
      !define MUI_FINISHPAGE_SHOWREADME_NOTCHECKED
      !define MUI_FINISHPAGE_SHOWREADME_TEXT "Create Desktop Shortcut"
      !define MUI_FINISHPAGE_SHOWREADME_FUNCTION finishpageaction
  !insertmacro MUI_PAGE_FINISH
  
  !insertmacro MUI_UNPAGE_CONFIRM
  !insertmacro MUI_UNPAGE_INSTFILES

;Languages
 
  !insertmacro MUI_LANGUAGE "English"

; The stuff to install
Section "Sample Rate and BPM Calculator"

  SectionIn RO
  
  ; Set output path to the installation directory.
  SetOutPath $INSTDIR
  
  ; Put file there
  File "SRCalc.exe"
  File "License.txt"
  File "SRCalc.ico"

  ; Write the installation path into the registry
  WriteRegStr HKLM SOFTWARE\SampleRateAndBPMCalculator "Install_Dir" "$INSTDIR"
  
  ; Write the uninstall keys for Windows
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\SampleRateAndBPMCalculator" "DisplayName" "Sample Rate and BPM Calculator"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\SampleRateAndBPMCalculator" "DisplayVersion" "1.01"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\SampleRateAndBPMCalculator" "Publisher" "Zeta Centauri"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\SampleRateAndBPMCalculator" "DisplayIcon" "$INSTDIR\SRCalc.ico"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\SampleRateAndBPMCalculator" "UninstallString" '"$INSTDIR\uninstall.exe"'
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\SampleRateAndBPMCalculator" "NoModify" 1
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\SampleRateAndBPMCalculator" "NoRepair" 1
  WriteUninstaller "uninstall.exe"

SectionEnd

; Optional section (can be disabled by the user)
Section "Start Menu Shortcuts"

  CreateDirectory "$SMPROGRAMS\Zeta Centauri\Sample Rate and BPM Calculator"
  CreateShortCut "$SMPROGRAMS\Zeta Centauri\Sample Rate and BPM Calculator\Sample Rate and BPM Calculator.lnk" "$INSTDIR\SRCalc.exe" "" "" 0
  ;CreateShortCut "$SMPROGRAMS\Zeta Centauri\Sample Rate and BPM Calculator\Uninstall.lnk" "$INSTDIR\uninstall.exe" "" "$INSTDIR\uninstall.exe" 0
  WriteINIStr "$SMPROGRAMS\Zeta Centauri\Sample Rate and BPM Calculator\Sample Rate and BPM Calculator Website.url" "InternetShortcut" "URL" "http://zetacentauri.com/software_samplerateandbpmcalculator.htm"
 
SectionEnd

; Uninstaller

Section "Uninstall"
  
  ; Remove registry keys
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\SampleRateAndBPMCalculator"
  DeleteRegKey HKLM SOFTWARE\SampleRateAndBPMCalculator

  ; Remove files and uninstaller
  Delete $INSTDIR\SRCalc.exe
  Delete $INSTDIR\License.txt
  Delete $INSTDIR\SRCalc.ico
  Delete $INSTDIR\uninstall.exe

  ; Remove shortcuts, if any
  Delete "$SMPROGRAMS\Zeta Centauri\Sample Rate and BPM Calculator\*.*"
  Delete "$DESKTOP\Sample Rate and BPM Calculator.lnk"
  Delete "$SMPROGRAMS\Zeta Centauri\Sample Rate and BPM Calculator\Sample Rate and BPM Calculator Website.url"
  ;DeleteINISec "$SMPROGRAMS\Zeta Centauri\Sample Rate and BPM Calculator\Sample Rate and BPM Calculator Website.url" "InternetShortcut"

  ; Remove directories used
  RMDir "$SMPROGRAMS\Zeta Centauri\Sample Rate and BPM Calculator"
  RMDir "$SMPROGRAMS\Zeta Centauri"
  RMDir "$INSTDIR"

SectionEnd

Function LaunchProgram
  ExecShell "" "$SMPROGRAMS\Zeta Centauri\Sample Rate and BPM Calculator\Sample Rate and BPM Calculator.lnk"
FunctionEnd

Function finishpageaction
  CreateShortcut "$DESKTOP\Sample Rate and BPM Calculator.lnk" "$INSTDIR\SRCalc.exe"
FunctionEnd
