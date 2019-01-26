/* Engine Implements WriteConsoleOutput function for faster console output*/

#pragma once

#include <string>
#include <windows.h>

using std::string;

class Engine
{
	HANDLE console;
	CONSOLE_SCREEN_BUFFER_INFO csbinfo;
	COORD  cursorPosition = { 0,0 };
	CHAR_INFO* buffer;

public:

	int bsize;
	int screen_width, screen_height;

	Engine();
	Engine(int screen_width, int screen_height);
	~Engine();

	int       moveXY(int x, int y);
	void    printCh(char ch);
	void    printW(string str);

	void    mvprintCh(int x, int y, char ch);
	void    mvprintW(int x, int y, string str);

	char   readCh();

	void    refresh();
	void    clear();
};