#ifndef ACCOUNTINFO_H
#define ACCOUNTINFO_H

#include "serverATM.h"
#include "personInfo.h"

class accountInfo:public personInfo {
public:
	int depoInfo();							//입금 함수
	int withInfo();							//출금 함수
	int transferInfo(accountInfo *person);	//계좌이체 함수
	void checkInfo();						//계좌정보 확인 함수
	void checkInfo(int num);				//세부 계좌정보 확인 함수 @overloading
};


#endif