#include "skill.h"

//스킬 이름 출력
void Skill::PrintskillName() {
	cout << name;
}

bool Skill::Attacks() {
	return behaviour == 0;
}

bool Skill::Upgrades() {
	return (behaviour == 1 || behaviour == 2);
}

bool Skill::Heals() {
	return behaviour == 3;
}

bool Skill::IsWater() {
	return type == "물";
}

bool Skill::IsGrass() {
	return type == "풀";
}

bool Skill::IsElectricity() {
	return type == "전기";
}

bool Skill::IsFire()
{
	return type == "불";
}

bool Skill::IsNormal() {
	return type == "노말";
}

//파일에 스킬 저장
void Skill::Save() {
	string word;
	ifstream i("skill_list.txt");
	if (!i.is_open()) return;
	while (i >> word) {
		if (word == name) {
			i.close();
			return;
		} //해당 이름의 스킬이 이미 존재하면 저장하지 않음
	}
	i.close();

	ofstream o("skill_list.txt", ios::app);
	if (!o.is_open()) return;
	o << name << ' ' << damageMultiplier << ' ' << attackMultiplier << ' ' << defenseMultiplier << ' ' << behaviour << ' ' << type << mp <<'\n';
	o.close();
}
//스킬 사용
double Skill::Use() {
	switch (behaviour) {
	case 0:
		return damageMultiplier;
	case 1:
		return attackMultiplier;
	case 2:
		return defenseMultiplier;
	case 3:
		return  0.1;
	default:
		return 0;
		//여기로 오면 안 됨
	}
}