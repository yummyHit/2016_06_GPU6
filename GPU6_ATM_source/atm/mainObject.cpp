#include <iostream>
#include <Windows.h>
#include "accountInfo.h"
using namespace std;
#define MAX_SIZE 100

int main() {
	accountInfo *person = new accountInfo[MAX_SIZE];				//최대 사용자 100명
	int select, a = 0, i = 0;

	while (1) {
		cout << "┌ㅡㅡ ## GPU6's ATM Machine 시작 ##  ㅡㅡ┐" << endl;
		person[i].showMenu();		//선택 메뉴 출력
		cin >> select;	//1번~7번 메뉴 입력받는 select 변수

		switch (select) {

		case 1:
			i = person[i].searchInfo(person, a);	//변수 i값에 사용자에 해당하는 index값 저장(로그인 기능)
			break;

		case 2:
			for(int j = 1; j < MAX_SIZE; j++)
				if(person[j].checkID() == 0) {		//사용자가 등록되어있지 않은 index로 이동하기위한 반복문
					a = j;
					break;
				}
			i = person[a].insertInfo(person, a);	//사용자 등록(회원가입 기능)
			break;

		case 3:
			person[i].depoInfo();	//입금실행
			break;

		case 4:
			person[i].withInfo();	//출금실행
			break;

		case 5:
			person[i].transferInfo(person);	//계좌이체실행
			break;

		case 6:
			while(1) {
				cout << "│   전체 정보를 보시려면 1번,\n│   세부 정보를 보시려면 2번을\n│   입력하세요 => ";
				cin >> a;
				if (a == 1) {
					person[i].checkInfo();	//계좌정보실행(전체 정보)
					break;
				}
				else if (a == 2) {
					person[i].checkInfo(a);	//계좌정보실행(선택 정보)
					break;
				}
				else
					cout << "│   번호를 잘못 입력하셨습니다." << endl;
			}
			a = i;
			break;

		case 7:
			cout << "│     ## GPU6's ATM Machine 종료 ##" << endl;
			cout << "└ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
			delete[] person;
			exit(1);	//종료

		default:
			cout << "│       ## 잘못 입력하셨습니다 ##\n│    메뉴에 있는 번호만 입력해주세요\n";
		}
		cout << "└ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
		system("pause"); system("cls");
		//microsoft의 windows 명령 프롬프트에서 제공하는 pause(일시정지), cls(버퍼지우기) 명령어 실행
	}
}