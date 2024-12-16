/* ****************************************************************
 * @author: Jephthah Orobia
 * @app name: whats-next.h
 * @app desc: This library shall contain a function that retrieve
 *              the maximum character per line
 * ****************************************************************/

#ifndef _MAXCHARPERLINE_FUNC
#define _MAXCHARPERLINE_FUNC

#include <windows.h>

int getMaxCharPerLine() {
    // Get the handle of the standard output device (console)
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    // Variable to store console screen buffer info
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    
    // Retrieve the screen buffer info
    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        // Calculate the width of the console window
        int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        return consoleWidth;
    } else {
        return 0;
    }
}

#endif
