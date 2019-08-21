#pragma once
#include "Monster.h"
#include "Player.h"
#include "Pokemon.h"

class BattleManager {       //πË∆≤æ¿ ∞¸∏Æ
private :
	BattleManager();
	static BattleManager *instance;   //ΩÃ±€≈Ê ∆–≈œ¿ª ¿ß«— ¿ŒΩ∫≈œΩ∫
	Monster *M;
	Pokemon *P;
	bool isWin;

public :
	static BattleManager *GetInstance();  //ΩÃ±€≈Ê ∆–≈œ¿ª ¿ß«— getter

	//set
	void SetIsWin(bool _isWin) { isWin = _isWin; }

	//get
	Monster *GetMonster() { return M; }
	Pokemon *GetPokemon() { return P; }
	bool GetIsWin() { return isWin; }

	void CreateMonster();
	bool Action(int, Creature*, Creature*);
	bool Run();
	void CopyPokemon();
};