#include <cstdlib>
#include <cstdio>
#include "Engine.hpp"

Engine::Engine()
{
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &csbinfo);
	screen_width = csbinfo.srWindow.Right - csbinfo.srWindow.Left;
	screen_height = csbinfo.srWindow.Bottom - csbinfo.srWindow.Top;

	bsize = screen_width * screen_height;

	buffer = new CHAR_INFO[bsize];
	cleanbuffer = new CHAR_INFO[bsize];
	for (int i = 0; i < bsize; i++)
	{
		buffer[i].Char.AsciiChar = ' ';
		cleanbuffer[i].Char.AsciiChar = ' ';
		buffer[i].Attributes = csbinfo.wAttributes;
		cleanbuffer[i].Attributes = csbinfo.wAttributes;
	}
}

void Engine::_clearbuffer(CHAR_INFO* buff)
{
	for (int i = 0; i < bsize; i++)
	{
		buff[i].Char.AsciiChar = ' ';
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
		buffer[cursorPosition.Y * screen_width + cursorPosition.X+i].Char.AsciiChar = str[i];
}

int Engine::mvprintCh(int x, int y, char ch)
{
	if (moveXY(x, y))
		printCh(ch);
	else
		return 0;
}

int Engine::mvprintW(int x, int y, string str)
{
	if (moveXY(x, y))
		printW(str);
	else
		return 0;
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
	nbuffer = buffer;
	buffer = cleanbuffer;
	cleanbuffer = nbuffer;
	_clearbuffer(cleanbuffer);
}

void Engine::clrscreen()
{
	DWORD size, n;
	COORD cstart = { 0,0 };
	size = screen_width * screen_height;
	if (!FillConsoleOutputCharacter(console, (TCHAR) ' ', size, cstart, &n))
	{
		return;
	}

	if (!FillConsoleOutputAttribute(console, csbinfo.wAttributes, size, cstart, &n))
	{
		return;
	}
		SetConsoleCursorPosition(console, cursorPosition);
}