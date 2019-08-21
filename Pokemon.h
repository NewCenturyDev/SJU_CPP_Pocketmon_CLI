#pragma once
#include "Creature.h"

class Pokemon : public Creature {
private :
	int selectAct;       //행동 입력
	int selectSkill;     //스킬 입력
public :
	Pokemon();

	//setter

	//getter

	void TakeExp(int e_exp);    //EXP획득
	void PokemonLoad(int);
	void PlayerPokemonLoad(ifstream &);
};
