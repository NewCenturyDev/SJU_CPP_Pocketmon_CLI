#pragma once
#include <fstream>
using namespace std;

class Text {

	/* 구조체 정의 */
	typedef struct textunit {
		string title;	//텍스트 제목
		string text;	//텍스트 내용
		int type;	//텍스트 타입
		int x, y;	//텍스트 좌표
	}TEXT;

private:
	TEXT buffer;	//임시 구조체(버퍼)
	ifstream filePtr;
	ofstream filePtrForDebug;
	int fileindex, seqindex;	//파일 인덱스와 시퀀스(n번 Scene의 m번째 출력되는 텍스트 -> fileindex==n, seqindex==m)

public:
	//Constructor, Destructor
	Text() { ; }
	~Text() { ; }

	//Get/Set Function
	//Text 클래스의 내용 변경
	void LoadText();	//구조체를 파일에 저장
	void SaveText();	//구조체를 파일으로부터 읽어옴

	//UI 추상 함수 구현
	void Display();	//화면 출력
};

