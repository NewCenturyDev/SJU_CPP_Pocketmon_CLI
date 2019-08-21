#include "skillmanager.h"

SkillManager *SkillManager::manager = nullptr;

SkillManager::SkillManager() {
	ifstream f(".\\Skill\\skill_list.txt");
	string name, type;
	double dmg, atk, def;
	int behaviour, mp;
	while (f >> name && f >> dmg && f >> atk && f >> def && f >> behaviour && f >> type && f >> mp) { //파일에서 불러오기
		skillList.push_back(new Skill(name, dmg, atk, def, behaviour, type, mp));
	}
	f.close();
}

SkillManager* SkillManager::GetInstance() {
	if (manager == nullptr) manager = new SkillManager();
	return manager;
}

Skill* SkillManager::GetSkill(int index) {
	if (skillList.size() > index) {
		return skillList[index];
	}
	else return nullptr;
}

Skill* SkillManager::GetSkill(string name) {
	for (int i = 0; i < skillList.size(); i++) {
		if (skillList[i]->GetskillName() == name) {
			return skillList[i];
		}
	}
	return nullptr;
}

void SkillManager::SetSkill(int index, Skill* skill) {
	if (skillList.size() > index) {
		skillList[index] = skill;
	}
	else if (skillList.size() == index) {
		AddSkill(skill);
	}
	else return;
}

void SkillManager::AddSkill(Skill* skill) {
	skillList.push_back(skill);
}
