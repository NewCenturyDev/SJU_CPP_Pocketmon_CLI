#pragma once
#include "UI.h"
#include <fstream>
#include <string>

class Image:public UI
{
private:
	int width;
	int height;

public:
	Image();
	Image(int, int, string);
	~Image();

	void SetArea(int _w, int _h) { width = _w; height = _h; }
	void ClearArea();
	

	void Display();
};

