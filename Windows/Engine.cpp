#include "Engine.hpp"

Engine::Engine()
{
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &csbinfo);
	screen_width =  csbinfo.srWindow.Right - csbinfo.srWindow.Left;
	screen_height = csbinfo.srWindow.Bottom - csbinfo.srWindow.Top;

	bsize = screen_width * screen_height;

	buffer = new CHAR_INFO[bsize];

	for (int i = 0; i < bsize; i++)
	{
		buffer[i].Char.AsciiChar = ' ';
		buffer[i].Attributes = csbinfo.wAttributes;
	}
}

int Engine::moveXY(int x, int y)
{
	if (x > screen_width || y > screen_height)
		return 0;

	cursorPosition.X = x;
	cursorPosition.Y = y;
    return 1;
}

void Engine::printCh(char ch)
{
	buffer[cursorPosition.Y * screen_width + cursorPosition.X].Char.AsciiChar = ch;
}

void Engine::printW(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if(moveXY(cursorPosition.X+i, cursorPosition.Y))
		printCh(str[i]);
	}
}

void Engine::mvprintCh(int x, int y, char ch)
{
	if (moveXY(x, y))
		printCh(ch);
}

void Engine::mvprintW(int x, int y, string str)
{
	if (moveXY(x, y))
		printW(str);
}

char Engine::readCh()
{
	return buffer[cursorPosition.Y * screen_width + cursorPosition.X].Char.AsciiChar;
}


void Engine::refresh()
{
	DWORD size, n;
	COORD cstart = { 0,0 };
	COORD csize = { screen_width , screen_height };
	SMALL_RECT rect = { cstart.X,cstart.Y,csize.X,csize.Y };
	WriteConsoleOutput(console, buffer, csize, cstart, &rect);
}

void Engine::clear()
{
	for (int i = 0; i < bsize; i++)
	{
		buffer[i].Char.AsciiChar = ' ';
	}
}