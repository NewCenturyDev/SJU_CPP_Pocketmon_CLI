#include <iostream>
#include <fstream>
#include <string>
#include "Statistics.h"

using namespace std;

const int BattleWin = 5;
const int BattleLose = 6;

Statistics *Statistics::instance = nullptr;

Statistics* Statistics::GetInstance() {
	if (instance == nullptr) {
		instance = new Statistics();
	}
	return instance;
}

void Statistics::SaveStatistics(string playername) {
	ofstream fileptr;

	fileptr.open(".\\Stats\\" + playername + ".txt");
	fileptr << games << endl;
	fileptr << wins << endl;
	fileptr << loses << endl;
	fileptr << winrate << endl;

	return;
}

void Statistics::LoadStatistics(string playername) {
	ifstream fileptr;
	string temp;

	//파일 열기
	fileptr.open(".\\Stats\\" + playername + ".txt");

	//게임횟수 읽어오기
	getline(fileptr, temp);
	games = atoi(temp.c_str());

	//승리횟수 읽어오기
	getline(fileptr, temp);
	wins = atoi(temp.c_str());

	//패배횟수 읽어오기
	getline(fileptr, temp);
	loses = atoi(temp.c_str());

	//승률 읽어오기
	getline(fileptr, temp);
	winrate = atof(temp.c_str());

	return;
}

void Statistics::UpdateStatistics() {
	int WinorLose;

	games++;

	//배틀매니저를 통해 이겼는지 확인
	if (BattleManager::GetInstance()->GetIsWin()) {  //이겼을때
		wins++;
		WinorLose = BattleWin;
	}
	else {                                           //졌을때
		loses++;
		WinorLose = BattleLose;
	}

	winrate = (double)wins / (double)games;

	//씬에서의 텍스트 갱신
	SceneManager::GetInstance()->GetSceneList()[WinorLose]->SearchText("TotalGames")->SetText(games);
	SceneManager::GetInstance()->GetSceneList()[WinorLose]->SearchText("WinRates")->SetText(winrate * 100);
	SceneManager::GetInstance()->GetSceneList()[WinorLose]->SearchText("Wins")->SetText(wins);
	SceneManager::GetInstance()->GetSceneList()[WinorLose]->SearchText("Loses")->SetText(loses);
}