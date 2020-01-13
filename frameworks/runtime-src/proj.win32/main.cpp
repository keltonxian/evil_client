#include "main.h"
#include "AppDelegate.h"
#include "cocos2d.h"

#include <iostream>

USING_NS_CC;

using namespace std;

// peter: now, using parameter to control console

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
	// peter: if there is a parameter, len of lpCmdLine > 0, means use console
	int USE_WIN32_CONSOLE = _tcslen(lpCmdLine);
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);  

	if (USE_WIN32_CONSOLE > 0) {
		AllocConsole();
		freopen("CONIN$", "r", stdin);
		freopen("CONOUT$", "w", stdout);
		freopen("CONOUT$", "w", stderr);
	}
    // peter: debug

    // create the application instance
    AppDelegate app;
    int ret = Application::getInstance()->run();
	
	if (USE_WIN32_CONSOLE > 0) {
		FreeConsole();
	}

    return ret;
}
