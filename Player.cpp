#include <iostream>
#include <string>
#include "Player.h"
#include "Creature.h"

using namespace std;

Player::Player() {

}

Player *Player::instance = nullptr;

Player *Player::GetInstance() {
	if (instance == nullptr) {
		instance = new Player();
	}
	return instance;
}

void Player::SaveProfile() {
	ofstream fileptr;

	fileptr.open(".\\Profile\\" + playerName + ".txt", ios::trunc);
	fileptr << playerName << endl;
	fileptr << playerAge << endl;
	fileptr << playerGender << endl;
	fileptr << P->GetName() << ' ';

	for (int i = 0; i < 4; i++) {
		fileptr << P->GetSkills()[i].GetskillName() << ' ';
	}

	fileptr << P->GetType() << ' ' << P->GetHp() << ' ' << P->GetMp() << ' ' << P->GetAtk() << ' ' << P->GetDef() << ' ' << P->GetLevel() << ' ' << P->GetExp();
	fileptr.close();

	return;
}

void Player::LoadProfile(string temp) {
	ifstream fileptr;

	//파일 열기
	fileptr.open(".\\Profile\\" + temp + ".txt");
	//플레이어 이름 읽어오기
	getline(fileptr, playerName);
	//플레이어 연령 읽어오기
	getline(fileptr, temp);
	playerAge = atoi(temp.c_str());
	//플레이어 성별 읽어오기
	getline(fileptr, temp);
	playerGender = atoi(temp.c_str());
	//플레이어 포켓몬 읽어오기

	P->PlayerPokemonLoad(fileptr);
	

	//getline(fileptr,여기에 저장할 string을 저장하면 됩니다.);
	fileptr.close();

	return;
}