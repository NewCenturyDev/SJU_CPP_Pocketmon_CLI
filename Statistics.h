#pragma once
#include "BattleManager.h"
#include "SceneManager.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Statistics {
	//player 클래스를 상속하면 안됨. player 클래스의 싱글톤 구조가 파괴되기 때문임.
private:
	static Statistics *instance;	//인스턴스
	double winrate;	//승률
	int wins;	//승수
	int loses;	//패수
	int games;	//전체 게임수

	Statistics() { ; }

public:
	/* Constructors */
	//싱글 톤 방식 사용으로 생성자 사용 제한.
	static Statistics *GetInstance();	//인스턴스 생성

	/* GET/SET Function */
	//Getter
	int Getwinrate() {
		return winrate * 100;
	}

	int Getwins() {
		return wins;
	}

	int Getloses() {
		return loses;
	}

	int Getgames() {
		return games;
	}

	//승/패/게임 횟수를 임의로 변경하지 못하도록 setter는 미지원.

	/* Functionailty */
	void InitStatistics() {	//게임 실행 초기에 플레이어 정보를 생성한 이후 통계도 같이 생성
		wins = 0;
		loses = 0;
		games = 0;
		winrate = 0.0;
		return;
	}

	void LoadStatistics(string playername);	//게임 실행 초기에 플레이어 정보를 로드한 이후 이 함수를 호출하여 통계 로드.
	void SaveStatistics(string playername);	//게임 종료 직전에 이 함수를 호출하여 통계 저장.
	void UpdateStatistics();                //배틀 종료 후 마지막에 호출, 이겼을때 졌을때 구분

};