
need to download NSIS (Nullsoft Scriptable Install System)
http://rj.baidu.com/soft/detail/16386.html?ald

File:
ec.nsi	installer scripting file (if we add res may need to change this)


how to build installer: (in this folder)
makensis ec.nsi

output: ec.exe

usually vcredist_x86.exe will be included in the installer
if not, we need to give it to the user
note:
vcredist_x86.exe /quiet  = auto accept the license and install

----- 
glewinfo.exe :  use to check opengl version, run it, will generate glewinfo.txt

