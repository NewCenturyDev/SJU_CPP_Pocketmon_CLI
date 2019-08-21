#include "UI.h"

UI::UI()
{
}


UI::~UI()
{
}

void UI::SetTitle(string _title)
{
	title = _title;
}

void UI::SetCOORD(int _x, int _y)
{
	x = _x;
	y = _y;
}

void UI::gotoxy(int _x, int _y)
{
	COORD pos = { _x,_y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}