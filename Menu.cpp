#include "Menu.h"



Menu::Menu() :UI()
{
	//현재 이 객체가 Menu 타입이다
	//메뉴의 0번은 항상 뒤로가기이다
	AddItem("0. Back");
	type = 1;
}

Menu::Menu(int _x, int _y, string _title) :UI()
{
	SetCOORD(_x, _y);
	SetTitle(_title);
	AddItem("0. Back");
	type = 1;
}

Menu::~Menu()
{
}

void Menu::AddItem(string _item)
{
	items.push_back(_item);
}

void RemoveItem(int _index)
{

}

void Menu::Display()
{
	//메뉴의 모든 항목을 순서대로 출력한다
	//cout << "Menu::Display" << endl;
	int i, line = 0;
	for (i = 1; i < items.size(); i++)
	{
		gotoxy(x, y + (i - 1));
		cout << items[i];
	}
	cout << endl;
	//gotoxy(x, y + i);
	//cout << items[0];	//맨 마지막 줄에 Back 항목을 보여준다
}
