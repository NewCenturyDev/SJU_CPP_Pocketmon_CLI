#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class UI
{
protected:	
	//World Coordinates
	int x;
	int y;
	//type of content
	int type;
	string title;

public:
	UI();
	~UI();
	//Getter, Setter
	string GetTitle() { return title; }
	void SetTitle(string _title);

	int GetType() { return type; }
	int GetX() { return x; }
	int GetY() { return y; }
	void SetCOORD(int _x, int _y);

protected:
	virtual void Display() = 0;
	void gotoxy(int _x, int _y);
};

