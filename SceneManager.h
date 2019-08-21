#pragma once
#include "Scene.h"
#include <io.h>
#include <vector>
#include <direct.h>

using namespace std;

class SceneManager
{
private:
	SceneManager();		
	char currentDir[1000];				// 생성됨과 동시에 지정된 경로의 모든 파일들을 읽어 sceneList에 scene 정보를 저장한다
	string path;						// Scene 폴더의 위치, SceneManager의 생성자에서 초기화시킨다
	static SceneManager *instance;		// SceneManager 는 하나만 존재한다 -> 싱글톤 패턴으로 구현
	vector<Scene*> sceneList;			// Scene 파일을 읽어 Scene 정보를 저장할 배열

public:
	static SceneManager* GetInstance();
	~SceneManager();

	//Getter
	vector<Scene*> GetSceneList() { return sceneList; }
	int GetListSize() { return sceneList.size(); }

	//Setter

	//Functionality
	void LoadScene();
	void AddScene(Scene *s);
	void ChangeScene(int _delay, int _index);	// _delay 만큼 기다렸다가 Scene 을 바꾼다
	void ChangeScene(int _index);	// _delay 없이 Scene 을 바로 바꾼다
};

