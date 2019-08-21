#pragma once
#include <iostream>
#include <string>
#include "Pokemon.h"

using namespace std;

class Player {
private:
	Player();
	static Player *instance;	//인스턴스
	string playerName;	//플레이어 이름
	int playerAge;	//플레이어 연령
	bool playerGender;	//0==남성, 1==여성
	Pokemon *P;	//플레이어가 가진 포켓몬
public:
	static Player *GetInstance();	//인스턴스 생성

	//set
	void SetplayerName(string name) {
		playerName = name;
	}
	void SetplayerAge(int age) {
		playerAge = age;
	}
	void SetplayerGender(bool gender) {
		playerGender = gender;
	}
	void SetPokemon() {
		P = new Pokemon();
	}

	//get
	string GetplayerName() {
		return playerName;
	}
	int GetplayerAge() {
		return playerAge;
	}
	bool GetplayerGender() {
		return playerGender;
	}
	Pokemon *GetPokemon() {
		return P;
	}

	void SaveProfile();	//프로필을 파일에 저장
	void LoadProfile(string);	//프로필을 파일에서 로드
};