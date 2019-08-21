#pragma once
#include "UI.h"

class Text:public UI
{
private:
	string text;

public:
	//Constructor, Destructor
	Text();
	Text(int, int, string, string);	//Coordinate x, Coordinate y, textTitle, text
	Text(int, int, string, int);	//Coordinate x, Coordinate y, textTitle, value
	~Text();
	
	//Getter, Setter
	string GetText() { return text;}
	//void LoadText();
	void SetText(string _text);
	void SetText(int _value);
	
	//UI 추상 함수 구현
	void Display();
};

