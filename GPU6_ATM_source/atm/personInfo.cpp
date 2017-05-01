#include <iostream>
#include "personInfo.h"
#define MAX_SIZE 100
using namespace std;

personInfo::personInfo() {
	*name = NULL; *pw = NULL; *accountNum = NULL;
	balance = 0;
};
void personInfo::showMenu() {
	cout << "��     ##### �޴��� �����ϼ��� #####      ��" << endl;
	cout << "��          1. ����� �α���              ��" << endl;
	cout << "��          2. ����� ���                ��" << endl;
	cout << "��          3. �Ա�                       ��" << endl;
	cout << "��          4. ���                       ��" << endl;
	cout << "��          5. ������ü                   ��" << endl;
	cout << "��          6. ���� ���� Ȯ��             ��" << endl;
	cout << "��          7. ����                       ��" << endl;
	cout << "���ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѦ�" << endl;
	cout << "��   ������ �޴� ��ȣ => ";
};						//���ø޴� ����Լ�
int personInfo::searchInfo(personInfo *person, int a) {
	char checkName[20], checkPw[20];
	for(int i = 0; i < MAX_SIZE; i++)
		if(*person[i].name != NULL)	//1���� ����ڶ� ����� �Ǿ��ִ°� üũ�ϱ����� �ݺ���
			a++;
	if(a == 0) {
		cout << "��   �����Ͱ� �������� �ʽ��ϴ�.\n��   ���� ����� ����� �ϼ���.\n";
		return a;	//a���� 0�̹Ƿ� ����� index�� ù��° �迭�� �� �� �ְ� ��ȯ
	}
	cout << "��   �̸� �Է� => ";
	cin >> checkName;
	for(int i = 0; i < MAX_SIZE; i++) {
		if(strcmp(person[i].name,checkName) == 0) {	//����� ���̵� ��ġ�ϸ� if�� ����
			cout << "��   ��й�ȣ �Է� => ";
			cin >> checkPw;
			if(strcmp(person[i].pw,checkPw) != 0)	//����� ��й�ȣ�� Ʋ���� if�� ����
				cout << "��      ### ��й�ȣ�� ��ġ���� �ʽ��ϴ� !! ###\n";
			else {									//����� ��й�ȣ�� ������ else�� ����
				cout << "��      ## ȯ���մϴ� " << checkName << " ���� !!##\n";
				a = i;								//����ڰ� �ִ� index�� ���� ���� ��ȯ�� a�� i�� ����
			}
			break;
		}
		else
			a = i;									//���̵� ��ġ���� ������ a = MAX_SIZE - 1 ����
	}
	if(a == (MAX_SIZE - 1))	//����� ���̵� ��ġ���� ���� ��, �� for���� ������ �ݺ��ǹǷ� ������ i���� a�� ���� ��
							//����� ���̵� �����Ƿ� ������ ���
		cout << "��   ����ڰ� �������� �ʽ��ϴ�.\n��   ���� ����� ����� �ϼ���.\n";
	return a;	//����ڰ� ����ִ� �迭�� index�� ��ȯ
};

int personInfo::insertInfo(personInfo *person, int a) {
	int count = 0;
	cout << "��      ## ����� ����� �����ϼ̽��ϴ�. ##" << endl;
	cout << "��   �̸� �Է� => ";
	cin >> name;
	for(int i = 0; i < MAX_SIZE; i++)				//������� �̸��� �ߺ��Ǵ��� �˻��ϴ� �ݺ���
		if(strcmp(person[i].name,name) == 0) {
			count++;								//��� �Է¹��� name�� person[i].name���� 1���� �����Ƿ�
			if(count == 2) {						//2��°�� �����̸��� �ִٴ� ���� �ߺ��ȴٴ� ��
				cout << "��   �̹� ���� �̸��� �����մϴ�.\n��   �ٽ� ������ �ּ���.\n";
				*name = NULL;						//���� index�� name�� �ʱ�ȭ ��Ų ��
				return a = 0;						//index�� 0���� ��ȯ
			}
		}
	cout << "��   ��й�ȣ �Է� => ";
	cin >> pw;
	cout << "��   ���¹�ȣ �Է� => ";
	cin >> accountNum;
	for(int i = 0; i < MAX_SIZE; i++)				//������� ���¹�ȣ�� �ߺ��Ǵ��� �˻��ϴ� �ݺ���
		if(strcmp(person[i].accountNum,accountNum) == 0) {
			count++;								//��� �Է¹��� accountNum�� person[i].accountNum���� 1���� �����Ƿ�
			if(count == 3) {						//�̸��ߺ�üũ count���� �̸��� �ߺ����� �ʾҴٸ� count�� 1�� ���������� count�� 3
				cout << "��   �̹� ���� ���¹�ȣ�� �����մϴ�.\n��   �ٽ� ������ �ּ���.\n";
				*name = NULL;						
				*accountNum = NULL;					//���� index�� name�� accountNum�� �ʱ�ȭ ��Ų ��
				return a = 0;						//index�� 0���� ��ȯ
			}
		}
	cout << "��      ### ����� ��� ���� !! ###" << endl;
	return a;
};

int personInfo::checkID() {			//����� ������ ��ϵ��� ���� �ε����� �������� �Լ�
	int count;
	if(*name == NULL) 
		return count = 0;			//�����Լ����� �� �Լ��� 0�̸� �ε����� ����
	return count = 1;				//�� �Լ��� 1�̸� �ε����� ������Ű�� ������ ��
};