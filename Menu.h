#pragma once
#include "UI.h"
#include <vector>

class Menu:public UI
{
private:
	vector<string> items;
public:
	//Constructor, Destructor
	Menu();
	Menu(int _x, int _y, string _title);
	~Menu();
	
	//Functionality
	void AddItem(string _item);
	void RemoveItem(int _index);

	//UI 추상함수 구현
	void Display();
};

