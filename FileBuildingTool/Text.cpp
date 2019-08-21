#include "Text.h"
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

void gotoxy(int _x, int _y) {
	COORD pos = { _x,_y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Text::LoadText() {
	string filename = to_string(fileindex) + "_" + to_string(seqindex) + "text.dat";
	filePtr.open(filename, ios::binary);
	filePtr.read((char*)&buffer, sizeof(TEXT));
	filePtr.close();
}

void Text::SaveText() {
	string filename;
	string temp;

	cout << "=========Jjap'ketmon Development Tool - DAT==========" << endl;
	cout << "이 기능은 Jjap'ketmon 의 디버그를 위한 기능입니다." << endl;
	cout << "text를 저장하기 위한 binary 파일을 생성하는 Development Tool 입니다." << endl;
	cout << "==============================================" << endl;
	
	cout << " 1단계 : File 이름을 설정합니다. 파일은 텍스트 메뉴 부분이 1회 바뀔 때마다 새로운 파일을 로드해야 합니다. 즉, 1회의 텍스트 출력에 1개의 파일을 사용합니다." << endl;

	cout << "Setting File Index == 씬 인덱스 넘버를 입력하시오" << endl;
	cin >> fileindex;
	cout << "Setting Seq Index == " << fileindex << "번 씬의 몇 번째 텍스트인지 고유 번호를 입력하시오" << endl;
	cin >> seqindex;
	filename = to_string(fileindex) + "_" + to_string(seqindex) + "text.dat";

	cout << "2단계 : 파일 내용을 입력합니다. 파일명은 " << filename << "입니다." << endl;

	cout << "Setting File Contents == 콘솔창 X 좌표를 입력하시오" << endl;
	cin >> buffer.x;
	cout << "Setting File Contents == 콘솔창 Y 좌표를 입력하시오" << endl;
	cin >> buffer.y;
	cout << "Setting File Contents == TEXT와 MENU Class를 구분하는 구분자를 입력하시오" << endl;
	cin >> buffer.type;
	cout << "Setting File Contents == 텍스트 제목을 입력하시오." << endl;
	cin.ignore();
	getline(cin, temp, '\n');	//공백문자 포함
	buffer.title = temp;
	cout << "Setting File Contents == 텍스트 내용을 입력하시오." << endl;
	getline(cin, temp, '\n');	//공백문자 포함
	buffer.text = temp;

	filePtrForDebug.open(filename, ios::binary);
	filePtrForDebug.write((char*)&buffer, sizeof(TEXT));
	filePtrForDebug.close();

}

void Text::Display() {
	system("cls");
	cout << "아래는 파일 읽기, 출력 테스트입니다." << endl;
	gotoxy(buffer.x, buffer.y);
	cout << buffer.text;
}

