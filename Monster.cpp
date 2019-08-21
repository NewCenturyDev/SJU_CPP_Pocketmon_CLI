#include <string>
#include "Monster.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Monster::Monster(string _name, string _type, int _hp, int _mp, int _atk, int _def, int _level, int _exp, int _hos) 
	: Creature(_name, _type, _hp, _mp, _atk, _def, _level, _exp)  {
	hos = _hos;
}

int Monster::SelectAct() {
	srand(static_cast<size_t>(time(0)));

	pattern = rand()%4;

	return pattern;
}

void Monster::SelectSkill() {
	int i;
	srand(static_cast<size_t>(time(0)));

	i = rand() % 3 + 1;

	switch (i) {
	case 1:
		name = "꼬마돌";
		type = "노말";
		skills[0] = *(SkillManager::GetInstance()->GetSkill("Tackle"));
		skills[1] = *(SkillManager::GetInstance()->GetSkill("Bite"));
		skills[2] = *(SkillManager::GetInstance()->GetSkill("Harden"));
		skills[3] = *(SkillManager::GetInstance()->GetSkill("Growth"));
		break;
	case 2:
		name = "태보해";
		type = "노말";
		skills[0] = *(SkillManager::GetInstance()->GetSkill("Bite"));
		skills[1] = *(SkillManager::GetInstance()->GetSkill("Headshot"));
		skills[2] = *(SkillManager::GetInstance()->GetSkill("Taebo"));
		skills[3] = *(SkillManager::GetInstance()->GetSkill("A+"));
		break;
	case 3:
		name = "피카츄";
		type = "전기";
		skills[0] = *(SkillManager::GetInstance()->GetSkill("Scratch"));
		skills[1] = *(SkillManager::GetInstance()->GetSkill("Thunderbolt"));
		skills[2] = *(SkillManager::GetInstance()->GetSkill("Growl"));
		skills[3] = *(SkillManager::GetInstance()->GetSkill("Nap"));
	}
	
}