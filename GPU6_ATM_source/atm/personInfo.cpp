#include <iostream>
#include "personInfo.h"
#define MAX_SIZE 100
using namespace std;

personInfo::personInfo() {
	*name = NULL; *pw = NULL; *accountNum = NULL;
	balance = 0;
};
void personInfo::showMenu() {
	cout << "│     ##### 메뉴를 선택하세요 #####      │" << endl;
	cout << "│          1. 사용자 로그인              │" << endl;
	cout << "│          2. 사용자 등록                │" << endl;
	cout << "│          3. 입금                       │" << endl;
	cout << "│          4. 출금                       │" << endl;
	cout << "│          5. 계좌이체                   │" << endl;
	cout << "│          6. 계좌 정보 확인             │" << endl;
	cout << "│          7. 종료                       │" << endl;
	cout << "├ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┘" << endl;
	cout << "│   선택할 메뉴 번호 => ";
};						//선택메뉴 출력함수
int personInfo::searchInfo(personInfo *person, int a) {
	char checkName[20], checkPw[20];
	for(int i = 0; i < MAX_SIZE; i++)
		if(*person[i].name != NULL)	//1명의 사용자라도 등록이 되어있는가 체크하기위한 반복문
			a++;
	if(a == 0) {
		cout << "│   데이터가 존재하지 않습니다.\n│   먼저 사용자 등록을 하세요.\n";
		return a;	//a값이 0이므로 사용자 index도 첫번째 배열이 될 수 있게 반환
	}
	cout << "│   이름 입력 => ";
	cin >> checkName;
	for(int i = 0; i < MAX_SIZE; i++) {
		if(strcmp(person[i].name,checkName) == 0) {	//사용자 아이디가 일치하면 if문 실행
			cout << "│   비밀번호 입력 => ";
			cin >> checkPw;
			if(strcmp(person[i].pw,checkPw) != 0)	//사용자 비밀번호가 틀리면 if문 실행
				cout << "│      ### 비밀번호가 일치하지 않습니다 !! ###\n";
			else {									//사용자 비밀번호가 맞으면 else문 실행
				cout << "│      ## 환영합니다 " << checkName << " 고객님 !!##\n";
				a = i;								//사용자가 있는 index로 가기 위한 반환값 a에 i값 대입
			}
			break;
		}
		else
			a = i;									//아이디가 일치하지 않을시 a = MAX_SIZE - 1 대입
	}
	if(a == (MAX_SIZE - 1))	//사용자 아이디가 일치하지 않을 때, 위 for문이 끝까지 반복되므로 마지막 i값을 a에 대입 후
							//사용자 아이디가 없으므로 에러문 출력
		cout << "│   사용자가 존재하지 않습니다.\n│   먼저 사용자 등록을 하세요.\n";
	return a;	//사용자가 들어있는 배열의 index값 반환
};

int personInfo::insertInfo(personInfo *person, int a) {
	int count = 0;
	cout << "│      ## 사용자 등록을 선택하셨습니다. ##" << endl;
	cout << "│   이름 입력 => ";
	cin >> name;
	for(int i = 0; i < MAX_SIZE; i++)				//사용자의 이름이 중복되는지 검사하는 반복문
		if(strcmp(person[i].name,name) == 0) {
			count++;								//방금 입력받은 name이 person[i].name에도 1개가 있으므로
			if(count == 2) {						//2번째로 같은이름이 있다는 것은 중복된다는 것
				cout << "│   이미 같은 이름이 존재합니다.\n│   다시 실행해 주세요.\n";
				*name = NULL;						//현재 index의 name을 초기화 시킨 후
				return a = 0;						//index값 0으로 반환
			}
		}
	cout << "│   비밀번호 입력 => ";
	cin >> pw;
	cout << "│   계좌번호 입력 => ";
	cin >> accountNum;
	for(int i = 0; i < MAX_SIZE; i++)				//사용자의 계좌번호가 중복되는지 검사하는 반복문
		if(strcmp(person[i].accountNum,accountNum) == 0) {
			count++;								//방금 입력받은 accountNum이 person[i].accountNum에도 1개가 있으므로
			if(count == 3) {						//이름중복체크 count에서 이름이 중복되지 않았다면 count는 1로 증가했으니 count는 3
				cout << "│   이미 같은 계좌번호가 존재합니다.\n│   다시 실행해 주세요.\n";
				*name = NULL;						
				*accountNum = NULL;					//현재 index의 name과 accountNum을 초기화 시킨 후
				return a = 0;						//index값 0으로 반환
			}
		}
	cout << "│      ### 사용자 등록 성공 !! ###" << endl;
	return a;
};

int personInfo::checkID() {			//사용자 정보가 등록되지 않은 인덱스로 가기위한 함수
	int count;
	if(*name == NULL) 
		return count = 0;			//메인함수에서 이 함수가 0이면 인덱스로 가고
	return count = 1;				//이 함수가 1이면 인덱스를 증가시키는 역할을 함
};