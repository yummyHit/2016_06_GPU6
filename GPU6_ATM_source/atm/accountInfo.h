#ifndef ACCOUNTINFO_H
#define ACCOUNTINFO_H

#include "serverATM.h"
#include "personInfo.h"

class accountInfo:public personInfo {
public:
	int depoInfo();							//�Ա� �Լ�
	int withInfo();							//��� �Լ�
	int transferInfo(accountInfo *person);	//������ü �Լ�
	void checkInfo();						//�������� Ȯ�� �Լ�
	void checkInfo(int num);				//���� �������� Ȯ�� �Լ� @overloading
};


#endif