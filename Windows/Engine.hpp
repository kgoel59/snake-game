/* Engine Implements WriteConsoleOutput function for faster console output*/

#ifndef  _ENGINE_
#define _ENGINE_

#include <string>
#include <windows.h>

using std::string;

class Engine
{
	HANDLE console;
	CONSOLE_SCREEN_BUFFER_INFO csbinfo;
	COORD  cursorPosition = { 0,0 };
	CHAR_INFO* buffer;
	int bsize;

public:

	int screen_width, screen_height;

	Engine();
	int       moveXY(int x, int y);
	void    printCh(char ch);
	void    printW(string str);

	void    mvprintCh(int x, int y, char ch);
	void    mvprintW(int x, int y, string str);

	char   readCh();

	void    refresh();
	void    clear();
};
#endif