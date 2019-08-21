#include "Scene.h"

//UI의 타입
const int TEXT = 0;
const int MENU = 1;
const int IMAGE = 2;

Scene::Scene()
{
	//in.open(_fileName, std::ifstream::in);
	//getline(in, sceneName);
	//getline(in, sceneIndex);
	//in.close();
}

Scene::~Scene()
{
	//in.close();
}

void Scene::LoadData()
{
	ifstream filePtr;
	int seqIndex = 1;
	while (true)
	{
		string filename = ".\\Text\\" + to_string(sceneIndex) + "\\text" + to_string(seqIndex)+".dat";
		
		filePtr.open(filename, ios::binary);
		if (filePtr.is_open() == false)
			break;

		filePtr.read((char*)&textBuffer, sizeof(TextBuffer));
		Text *t = new Text(textBuffer.x, textBuffer.y, textBuffer.title, textBuffer.text);
		AddText(t);
		filePtr.close();
		seqIndex++;
	}
}

void Scene::AddText(Text *t)
{
	UI *u;
	u = t;
	ui.push_back(u);
}

void Scene::AddMenu(Menu *m)
{
	UI *u;
	u = m;
	ui.push_back(u);
}

void Scene::AddImage(Image *image)
{
	UI *u;
	u = image;
	ui.push_back(u);
}

void Scene::Draw()
{
	//cout << "Draw() Called" << endl;
	//file을 프로젝트 디렉토리 안의 새로운 폴더 Scene에 저장하기 때문에 파일의 경로를 sceneName에 저장한다
	//file을 열어서 출력한다. 저장된 주소의 파일을 출력한다
	/*if (in.fail())
	{
		//"파일을 열지않고 텍스트만 출력"
	}
	else*/
	/*{
		in.open(sceneName.c_str(), std::ifstream::in);
		string in_line;
		system("cls");
		gotoxy(0, 0);
		while (getline(in, in_line))
		{
			cout << in_line << endl;
		 }
		in.close();
	}*/
	in.open(sceneName.c_str(), std::ifstream::in);
	string in_line;
	system("cls");
	gotoxy(0, 0);
	while (getline(in, in_line))
	{
		cout << in_line << endl;
	}
	in.close();
	//Print();
}

void Scene::Draw(string _menuTitle)
{
	//cout << "Draw() Called" << endl;
	//file을 프로젝트 디렉토리 안의 새로운 폴더 Scene에 저장하기 때문에 파일의 경로를 sceneName에 저장한다
	//file을 열어서 출력한다. 저장된 주소의 파일을 출력한다
	/*if (in.fail())
	{
		//"파일을 열지않고 텍스트만 출력"
	}
	else*/
	/*{
		in.open(sceneName.c_str(), std::ifstream::in);
		string in_line;
		system("cls");
		gotoxy(0, 0);
		while (getline(in, in_line))
		{
			cout << in_line << endl;
		 }
		in.close();
	}*/
	in.open(sceneName.c_str(), std::ifstream::in);
	string in_line;
	system("cls");
	gotoxy(0, 0);
	while (getline(in, in_line))
	{
		cout << in_line << endl;
	}
	in.close();
	Print(_menuTitle);
}

void Scene::Print(string _menuTitle)	// vector ui 에 들어있는 모든 오브젝트들을 출력한다
{
	if (ui.size() == 0)	//ui 리스트가 비어잇으면 리턴한다
		return;

	vector<UI*>::iterator iter;
	Text *t;
	Menu *m;
	Image *image;
	for (iter = ui.begin(); iter != ui.end(); iter++)
	{
		if ((*iter)->GetType() == TEXT)
		{
			t = (Text*)(*iter);
			t->Display();
		}
		else if ((*iter)->GetType() == MENU)
		{
			m = (Menu*)(*iter);
			if (m->GetTitle() == _menuTitle)
			{
				m->Display();
			}
		}
		else if((*iter)->GetType() == IMAGE)
		{
			image = (Image*)(*iter);
			image->Display();
		}
	}
}

void Scene::CleanArea()
{
	gotoxy(menuArea.x, menuArea.y);
	for (int j = 0; j < menuArea.height; j++)
	{
		for (int i = 0; i < menuArea.width; i++)
		{
			cout << " ";
		}
		gotoxy(menuArea.x, menuArea.y + j);
	}
}

void Scene::gotoxy(int _x, int _y)
{
	COORD pos = { _x, _y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

Text* Scene::SearchText(string _textTitle)
{
	vector<UI*>::iterator iter;
	Text *t;
	for (iter = ui.begin(); iter != ui.end(); iter++)
	{
		if ((*iter)->GetType() == TEXT)
		{
			t = (Text*)(*iter);
			if (t->GetTitle() == _textTitle)
			{
				return t;
			}
		}
	}

	return NULL;
}

void Scene::UpdateText(string _textTitle, string _text)
{
	vector<UI*>::iterator iter;
	Text *t;
	for (iter = ui.begin(); iter != ui.end(); iter++)
	{
		if ((*iter)->GetType() == TEXT)
		{
			t = (Text*)(*iter);
			if (t->GetTitle() == _textTitle)
			{
				t->SetText(_text);
				//t->Display();
			}
		}
	}
}

void Scene::UpdateText(string _textTitle, int _value)
{
	vector<UI*>::iterator iter;
	Text *t;
	for (iter = ui.begin(); iter != ui.end(); iter++)
	{
		if ((*iter)->GetType() == TEXT)
		{
			t = (Text*)(*iter);
			if (t->GetTitle() == _textTitle)
			{
				t->SetText(_value);
				//t->Display();
			}
		}
	}
}

void Scene::UpdateNDisplayText(string _textTitle, int _value)
{
	vector<UI*>::iterator iter;
	Text *t;
	for (iter = ui.begin(); iter != ui.end(); iter++)
	{
		if ((*iter)->GetType() == TEXT)
		{
			t = (Text*)(*iter);
			if (t->GetTitle() == _textTitle)
			{
				t->SetText(_value);
				t->Display();
			}
		}
	}
}