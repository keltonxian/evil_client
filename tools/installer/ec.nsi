; ec.nsi
; 
; usage:
; makensis ec.nsi 
;
; before this, build publish version of EvilCard
; cocos compile -p win32 -m release
; @see EvilCard\publish\win32
; @note -m debug (default) will output to EvilCard\runtime\win32
;
; output:
; ec.exe   (installer)
;
; target: 
; compress C:\workspace\evil_client\EvilCard\runtime\win32
; EvilCard.exe to the installer
; hard code installer path to desktop
;

;--------------------------------

Var BINDIR

LoadLanguageFile "${NSISDIR}\Contrib\Language files\SimpChinese.nlf"

Function .onInit
;;	Language "Simplified Chinese"
FunctionEnd

; The name of the installer
Name "决战王者"

; The file to write
OutFile "ec.exe"


; The default installation directory
; InstallDir $DESKTOP\EvilCard
;  program files need administrator (so we do not recommend)
; InstallDir "$PROGRAMFILES\决战王者"
; InstallDir "c:\决战王者"    ;  chinese NOT work
InstallDir "c:\EvilCard"

;  change the directory page text
DirText "准备安装[决战王者]" "注意:文件夹必须为英文"



; Request application privileges for Windows Vista
RequestExecutionLevel user

;--------------------------------

; Pages


Page directory
Page instfiles

;--------------------------------

; The stuff to install
Section "Executable" ;No components page, name is not important

  ; Set output path to the installation directory.
  SetOutPath $INSTDIR

  ; peter: set var for compiled binary (useless)
  StrCpy $BINDIR "C:\workspace\evil_client\EvilCard\runtime\win32"
  
;; publish=release   runtime=debug
  ; Put file there
  File ..\..\publish\win32\EvilCard.exe
  File ..\..\publish\win32\*.lua
  File ..\..\publish\win32\*.dll
  File /r ..\..\publish\win32\src
  File /r ..\..\publish\win32\res

;; msvcr100.dll is for Windows XP
  File msvcr100.dll
;; vcredist (execute with : /quiet)
;; peter: for quick debug, remove vc redist
  File vcredist_x86.exe

SectionEnd ; end the section


;; Section "Resource"  ; this may not show in installer
  ; Set output path to the installation directory.
;;   SetOutPath $INSTDIR\res
;;   File C:\workspace\evil_client\EvilCard\runtime\win32\res\*.*
;; SectionEnd ; end the section

;; Section "Vcdist"  ; this may not show in installer
;;   SetOutPath $INSTDIR\vcdist
;;   File C:\workspace\nsis\vcredist_x86.exe
;; SectionEnd ; end the section

Section "Exec vcdist" VCDIST
;;  SectionIn 1 2 3
  
;;	SearchPath $1 notepad.exe
;; MessageBox MB_OK "notepad.exe=$1"
;;	ExecWait '"$1"' $5

;; MessageBox MB_OK "Start VC distributable"
;;	ExecWait '"$INSTDIR"\vcredist_x86.exe /install /quiet' $5
	ExecWait '"$INSTDIR\vcredist_x86.exe "' $5

	BringToFront
SectionEnd


Section "创建快捷链接"
  CreateShortCut "$SMPROGRAMS\决战王者.lnk" "$INSTDIR\EvilCard.exe" ; use defaults for parameters, icon, etc.
  CreateShortCut "$Desktop\决战王者.lnk" "$INSTDIR\EvilCard.exe" ; use defaults for parameters, icon, etc.
SectionEnd

Section "Goodbye"
	MessageBox MB_OK "成功安装决战王者, 请关闭, 如有需要请重启电脑"
SectionEnd

