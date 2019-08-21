#include "Image.h"

Image::Image():UI()
{
	type = 2;
}

Image::Image(int _x, int _y,string _imageTitle) :UI()
{
	type = 2;
	SetCOORD(_x, _y);
	SetTitle(_imageTitle);
}

void Image::ClearArea()
{
	gotoxy(x, y);
	for (int j = 0; j < height; j++)
	{
		gotoxy(x, y + j);
		for (int i = 0; i < width; i++)
			cout << " ";
	}
}

Image::~Image()
{
}

void Image::Display()
{
	ifstream in;
	string path = ".\\Image\\" + title + ".txt";
	string in_line;
	
	in.open(path);
	int i = 0;
	while (getline(in, in_line))
	{
		gotoxy(x, y + i);
		cout << in_line;
		i++;
	}
	in.close();
}