#pragma once
#include <string>
#include <vector>
#include "skill.h"
class SkillManager {
private:
	//멤버 변수

	static SkillManager* manager;

	vector<Skill*> skillList;

	//생성자

	SkillManager();

public:
	//Get/Set

	static SkillManager* GetInstance();

	vector<Skill*> GetskillList() const {
		return skillList;
	}

	Skill* GetSkill(int);

	Skill* GetSkill(string);

	void SetSkill(int, Skill*);

	//기능

	void AddSkill(Skill*);
	
};