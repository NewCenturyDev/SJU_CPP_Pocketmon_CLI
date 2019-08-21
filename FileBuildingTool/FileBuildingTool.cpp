// ConsoleApplicationpjtool.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 

#include "Text.h"
#include <iostream>

int main()
{
	Text test;
	test.SaveText();	//파일에 구조체 정보 저장
	test.LoadText();	//파일에 저장한 정보 다시 읽어와서 확인
	test.Display();	//확인할 수 있게 화면에 출력
	cout << "\n\n" << endl;
	system("pause");
}