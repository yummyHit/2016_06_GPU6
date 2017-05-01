#include <iostream>
#include "accountInfo.h"
#define MAX_SIZE 100
using namespace std;


int accountInfo::depoInfo() {
	int addMoney = 0;
	if(*name == NULL) {	//����ڰ� ���� �� ������ ���
		cout << "��   ����ڰ� �������� �ʽ��ϴ�.\n��   ���� ����� ����� �ϼ���.\n";
		return 0;
	}
	cout << "��      ## �Ա��� �����ϼ̽��ϴ� ##" << endl;
	cout << "��   �󸶸� �Ա��Ͻðڽ��ϱ�? => ";
	cin >> addMoney;
	cout << "��   ���� �ܾ� : " << balance + addMoney << "��" << endl;
	return balance += addMoney;		//����ڰ� ���� �� �Է¹��� �Աݱݾ��� �ܾ׿� �߰�
};

int accountInfo::withInfo()  {
	int withdrawMoney = 0;
	if(*pw == NULL) {		//��й�ȣ�� ���ٴ� ���� ���̵� ���� ���̹Ƿ� ����ڰ� ���� �� ������ ���
		cout << "��   ����ڰ� �������� �ʽ��ϴ�.\n��   ���� ����� ����� �ϼ���.\n";
		return 0;
	}
	char checkpw[20];
	cout << "��      ## ����� �����ϼ̽��ϴ�. ##" << endl;
	cout << "��   ��й�ȣ�� �Է��ϼ��� => ";
	cin >> checkpw;
	if ((strcmp(pw,checkpw)) == 0) {	//�Է��� ��й�ȣ�� ����� ��й�ȣ�� ���Ͽ� ��ġ�ϸ� if�� ����
		cout << "��   �󸶸� ����Ͻðڽ��ϱ�?\n��   (�ִ� : 100,000,000��) => ";
		cin >> withdrawMoney;
		if (withdrawMoney > 100000000)		//�ִ� 1����� ������ ������ ���
			cout << "��   100,000,000�� �̻� ����� �� �����ϴ� !!" << endl;
		else if (withdrawMoney > balance)	//�ܾ׺��� ��ݱݾ��� ���� �� ������ ���
			cout << "��   �ܾ��� �����մϴ� !! �ܾ��� Ȯ���ϼ���." << endl;
		else if (withdrawMoney < 0)			//0������ ������ ������ ���
			cout << "��   0�� ���� ����� �� �����ϴ� !!" << endl;	
		else {
			cout << "��   ���� �ܾ� : " << balance - withdrawMoney << "��" << endl;
			return balance-=withdrawMoney;	//����ڵ� �ְ�, ��й�ȣ�� ��ġ�ϸ�, �ݾ׵� �����ϴٸ� ��ݱݾ��� �ܾ׿��� ����
		}
	}
	else
		cout << "��   ��й�ȣ�� ��ġ���� �ʽ��ϴ� !!\n��   ��й�ȣ�� Ȯ���ϼ���." << endl;
	return 0;
};

int accountInfo::transferInfo(accountInfo *person) {
	int transMoney = 0, checkNumber, a = 0;
	char accountTmp[20], checkPw[20], checkAccount[20];
	if(*accountNum == NULL) {	//���¹�ȣ�� �������� �ʴ� ���� ����ڰ� ���� ���̹Ƿ� ������ ���
		cout << "��   ������ü�� �� �� �����ϴ�.\n��   ����� ��� Ȥ�� �α����� ���ּ���.\n";
		return 0;
	}
	cout << "��      ## ���� ��ü�� �����ϼ̽��ϴ�. ##" << endl;
	cout << "��   ��ü �� ���� ���¹�ȣ�� �Է��ϼ��� => ";
	cin >> accountTmp;
	if(strcmp(accountTmp, accountNum) == 0) {	//�Է¹��� ���¹�ȣ�� �ڽ��� ���¹�ȣ�� ���Ͽ� ��ġ�Ѵٸ� ������ ���
		cout << "��   ���� ������� �����Դϴ�. �ڽſ��� ��ü�� �� �����ϴ�." << endl;
		return 0;
	}

	for(int i = 0; i < MAX_SIZE; i++) {
		if(strcmp(person[i].accountNum, accountTmp) == 0) {	//��ü ����� �� �����ϴ� ���¹�ȣ�̸� ����
			cout << "��   �Է��Ͻ� ���¹�ȣ�� " << person[i].accountNum <<" �Դϴ�.\n��   ������ 1��, Ʋ���� 2���� �Է��ϼ��� => ";
			cin >> checkNumber;
			if(checkNumber == 1) {	//���¹�ȣ�� �´ٰ� 1���� �Է��ϸ� �Աݹ��� ������ �ε����� ���� �� �ݺ��� ����
				a = i;
				break;
			}
			else if(checkNumber == 2) {	//���¹�ȣ�� Ʋ���ٰ� 2���� �Է��ϸ�
				cout << "��   ����ϼ̽��ϴ�.\n��   �ٽ� �������ּ���." << endl;
				return 0;		//������ü�ݾ� 0������ ��ȯ�Ͽ� ���� ���� ��ȯ
			}
			else {
				cout << "��   �߸� �Է��ϼ̽��ϴ�. �ٽ� �������ּ���." << endl;
				i--;
				continue;
			}
		}
		a = i;	//��ü ����� �� �����ϴ� ���¹�ȣ�� ������ MAX_SIZE - 1 ��ŭ�� ���� a�� ����
	}
	if(a == (MAX_SIZE - 1)) {	//a���� MAX_SIZE - 1 �̸� ���� ���¹�ȣ�� �������� �����Ƿ� ������ ���
		cout << "��   ��ü �� ���¹�ȣ�� �������� �ʽ��ϴ�.\n��   ���� ���¹�ȣ�� Ȯ���ϼ���.\n";
		return 0;		//������ü�ݾ� 0������ ���� ���� ��ȯ
	}
	
	cout << "��   ��й�ȣ�� �Է��ϼ��� => ";
	cin >> checkPw;

	if((strcmp(pw,checkPw)) == 0) {	//�Է¹��� ��й�ȣ�� ����� ��й�ȣ�� ��ġ�Ѵٸ�
		cout << "��   ��ü�� �ݾ��� �Է��ϼ���.\n��   (�ִ� 100,000,000��) => ";
		cin >> transMoney;
		if(transMoney > balance)		//�Է¹��� ��ü�ݾ��� �ܾ׺��� ���� �� ������ ���
			cout << "��   �ܾ��� �����մϴ� !! �ܾ��� Ȯ���ϼ���." << endl;
		else if(transMoney > 100000000)		//�Է¹��� ��ü�ݾ��� 1��� �̻��̸� ������ ���
			cout << "��   100,000,000�� �̻� ��ü�� �� �����ϴ� !!\n";
		else if(transMoney < 0)				//�Է¹��� ��ü�ݾ��� 0�� �����̸� ������ ���
			cout << "��   0�� ���� ��ü�� �� �����ϴ� !!\n";
		else {
			cout << "��   ��ü �� ����� ���¹�ȣ�� �Է��ϼ��� => ";
			cin >> checkAccount;
			if(strcmp(checkAccount, accountNum) == 0) {	//������� ���¹�ȣ�� ��ġ�ϴ��� 2��Ȯ�� �� ��ġ�Ѵٸ�
				person[a].balance += transMoney;	//������ ���¿� ������ü�ݾ׸�ŭ �߰�
				cout << "��   ���������� ��ü�� �Ϸ�Ǿ����ϴ�." << endl;
				return balance -= transMoney;	//������ü�ݾ��� ����� �ܾ׿��� ����
			}
			else
				cout << "��   ������� ���¹�ȣ�� Ʋ���ϴ�.\n��   ���¹�ȣ�� Ȯ���ϼ���." << endl;
		}
	}
	else
		cout << "��   ��й�ȣ�� ��ġ���� �ʽ��ϴ� !!\n��   ��й�ȣ�� Ȯ���ϼ���." << endl;
	return 0;
};

void accountInfo::checkInfo() {
	if(*name == NULL) {	//���� �ƹ� ����ڵ� ���õǾ����� ������ �������
		cout << "��   ���°� �������� �ʽ��ϴ�.\n��   ���� ����� ����� �ϼ���.\n";
		return;
	}
	cout << "��      ## ���� ������ Ȯ���մϴ�... ##" << endl;
	cout << "��   ����� �̸� : " << name << "\n��   ���¹�ȣ : " << accountNum << "\n��   �ܾ� : " << balance << "��" << endl;
};

void accountInfo::checkInfo(int num) {
	if(*name == NULL) {	//���� �ƹ� ����ڵ� ���õǾ����� ������ �������
		cout << "��   ���°� �������� �ʽ��ϴ�.\n��   ���� ����� ����� �ϼ���.\n";
		return;
	}
	while(1) {
		cout << "��   ���������� Ȯ���Ͻ÷��� 1��,\n��   �ܾ��� Ȯ���Ͻ÷��� 2����\n��   �Է��ϼ��� => ";
		cin >> num;
		if(num == 1) {
			cout << "��      ## ���� ������ Ȯ���մϴ�... ##" << endl;
			cout << "��   " << name << "���� ���¹�ȣ��\n��   " << accountNum << " �Դϴ�." << endl;
			break;
		}
		else if(num == 2) {
			cout << "��      ## ���� ������ Ȯ���մϴ�... ##" << endl;
			cout << "��   " << name << "���� �ܾ���\n��   " << balance << "�� �Դϴ�." << endl;
			break;
		}
		else
			cout << "��   ��ȣ�� �߸� �Է��ϼ̽��ϴ�." << endl;
	}
};