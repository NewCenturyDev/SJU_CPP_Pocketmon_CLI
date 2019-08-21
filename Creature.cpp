#include <iostream>
#include "Creature.h"
#include <string>

using namespace std;

Creature::Creature() {
	skills = new Skill[4];
}

Creature::Creature(string _name, string _type, int _hp, int _mp, int _atk, int _def, int _level, int _exp) {
	name = _name;
	type = _type;
	hp = _hp;
	mp = _mp;
	atk = _atk;
	def = _def;
	level = _level;
	exp = _exp;
	skills = new Skill[4];
	max_Hp = hp;
}

void Creature::Damaged(double damage, string e_type) {
	if (e_type == "노말") {
		hp -= damage;
	}
	
	else if (e_type == "불") {
		if (type == "물") { hp -= damage * 0.8; }
		else if (type == "풀") { hp -= damage * 1.2; }
		else { hp -= damage; }
	}

	else if (e_type == "물") {
		if (type == "불") { hp -= damage * 0.8; }
		else if (type == "전기") { hp -= damage * 1.2; }
		else { hp -= damage; }
	}

	else if (e_type == "전기") {
		if (type == "물") { hp -= damage * 0.8; }
		else if (type == "풀") { hp -= damage * 1.2; }
		else { hp -= damage; }
	}

	else if (e_type == "풀") {
		if (type == "전기") { hp -= damage * 0.8; }
		else if (type == "불") { hp -= damage * 1.2; }
		else { hp -= damage; }
	}

	if (hp < 0) {
		hp = 0;
	}
}

void Creature::AtkEnchanted(double mul) {
	atk = atk * mul;
}

void Creature::DefEnchanted(double mul) {
	def = def * mul;
}

void Creature::Healed(double rate) {
	hp += max_Hp * rate;
	if (hp > max_Hp) {
		hp = max_Hp;
	}
}

bool Creature::IsDeath() {
	if (hp <= 0) {
		return true;
	}
	return false;
}