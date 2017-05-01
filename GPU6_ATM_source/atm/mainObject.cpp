#include <iostream>
#include <Windows.h>
#include "accountInfo.h"
using namespace std;
#define MAX_SIZE 100

int main() {
	accountInfo *person = new accountInfo[MAX_SIZE];				//�ִ� ����� 100��
	int select, a = 0, i = 0;

	while (1) {
		cout << "���Ѥ� ## GPU6's ATM Machine ���� ##  �ѤѦ�" << endl;
		person[i].showMenu();		//���� �޴� ���
		cin >> select;	//1��~7�� �޴� �Է¹޴� select ����

		switch (select) {

		case 1:
			i = person[i].searchInfo(person, a);	//���� i���� ����ڿ� �ش��ϴ� index�� ����(�α��� ���)
			break;

		case 2:
			for(int j = 1; j < MAX_SIZE; j++)
				if(person[j].checkID() == 0) {		//����ڰ� ��ϵǾ����� ���� index�� �̵��ϱ����� �ݺ���
					a = j;
					break;
				}
			i = person[a].insertInfo(person, a);	//����� ���(ȸ������ ���)
			break;

		case 3:
			person[i].depoInfo();	//�Աݽ���
			break;

		case 4:
			person[i].withInfo();	//��ݽ���
			break;

		case 5:
			person[i].transferInfo(person);	//������ü����
			break;

		case 6:
			while(1) {
				cout << "��   ��ü ������ ���÷��� 1��,\n��   ���� ������ ���÷��� 2����\n��   �Է��ϼ��� => ";
				cin >> a;
				if (a == 1) {
					person[i].checkInfo();	//������������(��ü ����)
					break;
				}
				else if (a == 2) {
					person[i].checkInfo(a);	//������������(���� ����)
					break;
				}
				else
					cout << "��   ��ȣ�� �߸� �Է��ϼ̽��ϴ�." << endl;
			}
			a = i;
			break;

		case 7:
			cout << "��     ## GPU6's ATM Machine ���� ##" << endl;
			cout << "���ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
			delete[] person;
			exit(1);	//����

		default:
			cout << "��       ## �߸� �Է��ϼ̽��ϴ� ##\n��    �޴��� �ִ� ��ȣ�� �Է����ּ���\n";
		}
		cout << "���ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
		system("pause"); system("cls");
		//microsoft�� windows ��� ������Ʈ���� �����ϴ� pause(�Ͻ�����), cls(���������) ��ɾ� ����
	}
}