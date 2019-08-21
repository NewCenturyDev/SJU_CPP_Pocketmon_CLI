#include "BattleManager.h"
#include "Skill.h"
#include "Creature.h"
#include "Player.h"
#include "SceneManager.h"

#include <cstdlib>
#include <ctime>

const int BattleScene = 4;
const int BattleWin = 5;

BattleManager::BattleManager() {

}

BattleManager *BattleManager::instance = nullptr;

BattleManager *BattleManager::GetInstance() {
	if (instance == nullptr) {
		instance = new BattleManager();
	}
	return instance;
}

void BattleManager::CreateMonster() {
	int hp, mp, atk, def, lev, exp, hos;
	srand(static_cast<size_t>(time(0)));

	hp = P->GetHp() + rand() % 21 - 10;
	mp = P->GetMp() + rand() % 21 - 10;
	atk = P->GetAtk() + rand() % 7 - 3;
	def = P->GetDef() + rand() % 7 - 3;
	lev = P->GetLevel() + rand() % 3 - 1;
	if (lev == 0) { lev = 1; }
	exp = lev * 50;
	hos = rand() % 6;

	M = new Monster("몬스터", "노말", hp, mp, atk, def, lev, exp, hos);

	SceneManager::GetInstance()->GetSceneList()[BattleScene]->UpdateText("enemyLv", M->GetLevel());
	SceneManager::GetInstance()->GetSceneList()[BattleScene]->UpdateText("enemyName", M->GetName());
	SceneManager::GetInstance()->GetSceneList()[BattleScene]->UpdateText("enemyHp", M->GetHp());
	SceneManager::GetInstance()->GetSceneList()[BattleWin]->SearchText("Exp")->SetText(M->GetExp());
}

void BattleManager::CopyPokemon() {
	P = new Pokemon();
	*P = *(Player::GetInstance()->GetPokemon());

	SceneManager::GetInstance()->GetSceneList()[BattleScene]->UpdateText("playerLv", P->GetLevel());
	SceneManager::GetInstance()->GetSceneList()[BattleScene]->UpdateText("playerName", P->GetName());
	SceneManager::GetInstance()->GetSceneList()[BattleScene]->UpdateText("playerHp", P->GetHp());
	SceneManager::GetInstance()->GetSceneList()[BattleScene]->UpdateText("playerMp", P->GetMp());
}

bool BattleManager::Action(int i, Creature *O, Creature *E) {
	Skill *S = &O->GetSkills()[i];

	if (O->GetMp() < S->GetMp()) {
		return false;
	}

	switch (S->GetskillBehaviour()) {
	case 0:
		E->Damaged(S->Use() * O->GetAtk(), S->GetskillType());
		O->SetMp(O->GetMp() - S->GetMp());
		return true;

	case 1: 
		O->AtkEnchanted(S->Use()); 
		O->SetMp(O->GetMp() - S->GetMp());
		return true;

	case 2: 
		O->DefEnchanted(S->Use()); 
		O->SetMp(O->GetMp() - S->GetMp());
		return true;

	case 3: 
		if (O->GetHp() == O->GetMax_Hp()) {
			return false;
		}
		else {
			O->Healed(S->Use());
			O->SetMp(O->GetMp() - S->GetMp());
			return true;
		}
	default: return false;
	}
}

bool BattleManager::Run() {
	srand(static_cast<size_t>(time(0)));
	
	int possibility = rand() % 9 + 1;

	switch (M->GetHos()) {
	case 0:
		break;
	case 1:
		if (possibility <= 1) return false;
		break;
	case 2:
		if (possibility <= 2) return false;
		break;
	case 3:
		if (possibility <= 3) return false;
		break;
	case 4:
		if (possibility <= 4) return false;
		break;
	case 5:
		if (possibility <= 5) return false;
		break;
	}

	return true;
}