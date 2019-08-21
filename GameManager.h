#pragma once
#include "UI.h"
#include "Text.h"
#include "Menu.h"
#include "Scene.h"
#include "BattleManager.h"
#include "SceneManager.h"
#include "Monster.h"
#include "Player.h"
#include "SkillManager.h"
#include "Pokemon.h"
#include "Statistics.h"

#include <Windows.h>

class GameManager {
private :
	GameManager();
	static GameManager *instance;

public:
	static GameManager* GetInstance();
	void Run();
	int UserInput();
	void gotoxy(int, int);
};