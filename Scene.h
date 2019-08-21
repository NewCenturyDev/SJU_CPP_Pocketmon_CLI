#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <vector>
#include "UI.h"
#include "Menu.h"
#include "Text.h"
#include "Image.h"

using namespace std;

struct Area
{
	int x;
	int y;
	int width;
	int height;
}typedef Area;

struct TextBuffer
{
	string title;
	string text;
	int type;
	int x, y;
}typedef TextBuffer;

class Scene
{
private:
	string sceneName;
	int sceneIndex;
	vector<UI*> ui;
	ifstream in;
	TextBuffer textBuffer;
	Area menuArea;
public:
	Scene();
	~Scene();
	
	//Getter
	vector<UI*> GetUIList(){ return ui; }
	string GetSceneName() { return sceneName; }
	//string GetSceneIndex() { return sceneIndex; }

	//Setter
	void SetSceneName(string _sceneName) { sceneName = _sceneName; }
	void SetSceneIndex(int _sceneIndex) { sceneIndex = _sceneIndex; }
	void SetArea(int _x, int _y, int _w, int _h) { menuArea.x = _x; menuArea.y = _y; menuArea.width = _w; menuArea.height = _h; }
	
	//Functionality
	void LoadData();	//Scene마다 파일에 입력해둔 UI 오브젝트들을 불러와 vector<UI*> 에 저장한다
	void AddText(Text *t);
	void AddMenu(Menu *m);
	void AddImage(Image *image);

	void Draw();
	void Draw(string _menuTitle);
	void Print(string _menuTitle);//Text text
	void CleanArea();
	Text* SearchText(string _textTitle);
	void UpdateText(string _textTitle, string _text);
	void UpdateText(string _textTitle, int _value);
	void UpdateNDisplayText(string _textTitle, int _value);

private:
	void gotoxy(int _x, int _y);
};

