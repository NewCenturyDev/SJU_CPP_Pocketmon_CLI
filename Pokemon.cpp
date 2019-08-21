#include "Pokemon.h"

Pokemon::Pokemon() : Creature() {

}

void Pokemon::PokemonLoad(int index) {
	ifstream i;
	string skillNames[4];

	switch (index) {
	case 1:
		i.open(".\\Pokemon\\Pokemon1.txt");
		break;
	case 2:
		i.open(".\\Pokemon\\Pokemon2.txt");
		break;
	case 3:
		i.open(".\\Pokemon\\Pokemon3.txt");
		break;
	default:
		//여기 오면 안 됨
		return;
	}

	if (!i.is_open()) {
		cout << "Unable to open Pokemon" << index << ".txt";
		return;
	}

	i >> name;
	for (int j = 0; j < 4; j++) {
		i >> skillNames[j];
		skills[j] = *(SkillManager::GetInstance()->GetSkill(skillNames[j]));
	}

	i >> type >> hp >> mp >> atk >> def >> level >> exp;
	max_Hp = hp;
	i.close();
}

void Pokemon::PlayerPokemonLoad(ifstream &i) {
	string skillNames[4];

	i >> name;
	for (int j = 0; j < 4; j++) {
		i >> skillNames[j];
		skills[j] = *(SkillManager::GetInstance()->GetSkill(skillNames[j]));
	}

	i >> type >> hp >> mp >> atk >> def >> level >> exp;
	max_Hp = hp;
}

void Pokemon::TakeExp(int e_exp) {
	exp += e_exp;
	while (exp >= 100) {
		exp -= 100;
		level++;
		hp += 10;
		mp += 10;
		max_Hp = hp;
		atk += 3;
		def += 3;
	}

}