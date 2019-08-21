#include "SceneManager.h"

SceneManager* SceneManager::instance = nullptr;

SceneManager::SceneManager()
{
	_getcwd(currentDir, 1000);	//current project directory
	for (int i = 0; currentDir[i] != NULL; i++)
		path += currentDir[i];

	path += "\\Scene";			//now in 'Scene' directory
	//cout << path << endl;
}

SceneManager* SceneManager::GetInstance()
{
	if (instance == nullptr)
		instance = new SceneManager();

	return instance;
}

SceneManager::~SceneManager()
{
}

void SceneManager::LoadScene()
{
	_finddata_t fd;
	long handle;
	int result = 1;
	int sceneIndex = 0;
	handle = _findfirst((path+"\\*.txt").c_str(), &fd);	//Set handle 

	if (handle == -1)
	{
		cout << "No files in directory" << endl;
		return;
	}

	while (result != -1)	//Find all txt file in 'Scene' directory
	{
		Scene *s = new Scene();	//Generate new Scene and set name 'path + fileName'
		string fileName;
		for (int i = 0; fd.name[i] != NULL; i++)
			fileName += fd.name[i];

		s->SetSceneName(path +"\\"+fileName);
		s->SetSceneIndex(sceneIndex);
		sceneIndex++;
		sceneList.push_back(s);	//add new scene to sceneList
		result = _findnext(handle, &fd);	//find next file
	}
}

void SceneManager::AddScene(Scene *s)
{
	sceneList.push_back(s);
}

void SceneManager::ChangeScene(int _delay, int _index)
{
	//꾸미기 화면
	Sleep(_delay);

	system("cls");
	sceneList[_index]->Draw("firstMenu");
}

void SceneManager::ChangeScene(int _index)
{
	system("cls");
	sceneList[_index]->Draw("firstMenu");
}
