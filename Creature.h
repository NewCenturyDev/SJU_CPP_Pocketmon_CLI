#pragma once
#include <string>
#include "Skill.h"
#include "skillmanager.h"

using namespace std;

class Creature {
protected:

	string name;
	Skill *skills;
	string type;      //속성
	int max_Hp;
	int hp;
	int mp;
	double atk;
	double def;
	int level;
	int exp;

public:
	Creature();
	Creature(string, string, int, int, int, int, int, int);
	//setter
	void SetName(string _name) { name = _name; }
	void SetType();
	void SetHp(int _hp) { hp = _hp; }
	void SetMp(int _mp) { mp = _mp; }
	void SetAtk();
	void SetDef();
	void SetLevel();
	void SetExp();

	//getter
	string GetName() { return name; };
	string GetType() { return type; };
	int GetHp() { return hp; };
	int GetMax_Hp() { return max_Hp; }
	int GetMp() { return mp; };
	double GetAtk() { return atk; };
	double GetDef() { return def; };
	int GetLevel() { return level; };
	int GetExp() { return exp; };
	Skill *GetSkills() { return skills; };

	//function
	void Damaged(double damage, string e_prop);       //데미지 받음
	void AtkEnchanted(double mul);
	void DefEnchanted(double mul);
	void Healed(double rate);
	bool IsDeath();                               //hp=0이 되면 출력, ture 리턴
};
