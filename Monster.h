#pragma once
#include "Creature.h"
#include <string>

using namespace std;

class Monster : public Creature {
private:
	int hos;       //°ø°Ý¼º
	int pattern;
public:
	Monster(string, string, int, int, int, int, int, int, int);

	//setter
	void SetHos();
	//getter
	int GetHos() { return hos; }

	//function
	void SelectSkill();
	int SelectAct();
};