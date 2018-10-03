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
	CHAR_INFO* buffer, *nbuffer, *cleanbuffer;
	int bsize;

	void _clearbuffer(CHAR_INFO* buff);

public:

	int screen_width, screen_height;

	Engine();
	int    moveXY(int x, int y);
	void    printCh(char ch);
	void    printW(string str);

	int    mvprintCh(int x, int y, char ch);
	int    mvprintW(int x, int y, string str);

	char   readCh();

	void    refresh();
	void    clear();
	void   clrscreen();
};
#endif