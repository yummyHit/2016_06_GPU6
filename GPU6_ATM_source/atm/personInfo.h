#ifndef PERSONINFO_H
#define PERSONINFO_H

#include "serverATM.h"

class personInfo:public serverATM {
protected:
	char name[20], pw[20], accountNum[20];	//name : ����� �̸� //pw : ��й�ȣ //accountNum : ���¹�ȣ
	int balance;							//balance : �ܾ�
public:
	personInfo();							//protected ������ �ִ� ������
	void showMenu();						//���ø޴� ����Լ�
	int searchInfo(personInfo *person, int a);//����� �α��� �Լ�
	int insertInfo(personInfo *person, int a);//����� ��� �Լ�
	int checkID();							//����ڰ� ����ִ� �ε��� �˻��� �Լ�
};

#endif