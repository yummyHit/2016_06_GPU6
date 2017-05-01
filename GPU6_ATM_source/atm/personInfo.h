#ifndef PERSONINFO_H
#define PERSONINFO_H

#include "serverATM.h"

class personInfo:public serverATM {
protected:
	char name[20], pw[20], accountNum[20];	//name : 사용자 이름 //pw : 비밀번호 //accountNum : 계좌번호
	int balance;							//balance : 잔액
public:
	personInfo();							//protected 변수를 넣는 생성자
	void showMenu();						//선택메뉴 출력함수
	int searchInfo(personInfo *person, int a);//사용자 로그인 함수
	int insertInfo(personInfo *person, int a);//사용자 등록 함수
	int checkID();							//사용자가 비어있는 인덱스 검색용 함수
};

#endif