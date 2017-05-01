#include <iostream>
#include "accountInfo.h"
#define MAX_SIZE 100
using namespace std;


int accountInfo::depoInfo() {
	int addMoney = 0;
	if(*name == NULL) {	//사용자가 없을 때 에러문 출력
		cout << "│   사용자가 존재하지 않습니다.\n│   먼저 사용자 등록을 하세요.\n";
		return 0;
	}
	cout << "│      ## 입금을 선택하셨습니다 ##" << endl;
	cout << "│   얼마를 입금하시겠습니까? => ";
	cin >> addMoney;
	cout << "│   현재 잔액 : " << balance + addMoney << "원" << endl;
	return balance += addMoney;		//사용자가 있을 때 입력받은 입금금액을 잔액에 추가
};

int accountInfo::withInfo()  {
	int withdrawMoney = 0;
	if(*pw == NULL) {		//비밀번호가 없다는 것은 아이디가 없는 것이므로 사용자가 없을 때 에러문 출력
		cout << "│   사용자가 존재하지 않습니다.\n│   먼저 사용자 등록을 하세요.\n";
		return 0;
	}
	char checkpw[20];
	cout << "│      ## 출금을 선택하셨습니다. ##" << endl;
	cout << "│   비밀번호를 입력하세요 => ";
	cin >> checkpw;
	if ((strcmp(pw,checkpw)) == 0) {	//입력한 비밀번호와 사용자 비밀번호를 비교하여 일치하면 if문 실행
		cout << "│   얼마를 출금하시겠습니까?\n│   (최대 : 100,000,000원) => ";
		cin >> withdrawMoney;
		if (withdrawMoney > 100000000)		//최대 1억원이 넘으면 에러문 출력
			cout << "│   100,000,000원 이상 출금할 수 없습니다 !!" << endl;
		else if (withdrawMoney > balance)	//잔액보다 출금금액이 많을 때 에러문 출력
			cout << "│   잔액이 부족합니다 !! 잔액을 확인하세요." << endl;
		else if (withdrawMoney < 0)			//0원보다 작으면 에러문 출력
			cout << "│   0원 이하 출금할 수 없습니다 !!" << endl;	
		else {
			cout << "│   현재 잔액 : " << balance - withdrawMoney << "원" << endl;
			return balance-=withdrawMoney;	//사용자도 있고, 비밀번호도 일치하며, 금액도 적절하다면 출금금액을 잔액에서 차감
		}
	}
	else
		cout << "│   비밀번호가 일치하지 않습니다 !!\n│   비밀번호를 확인하세요." << endl;
	return 0;
};

int accountInfo::transferInfo(accountInfo *person) {
	int transMoney = 0, checkNumber, a = 0;
	char accountTmp[20], checkPw[20], checkAccount[20];
	if(*accountNum == NULL) {	//계좌번호가 존재하지 않는 것은 사용자가 없는 것이므로 에러문 출력
		cout << "│   계좌이체를 할 수 없습니다.\n│   사용자 등록 혹은 로그인을 해주세요.\n";
		return 0;
	}
	cout << "│      ## 계좌 이체를 선택하셨습니다. ##" << endl;
	cout << "│   이체 될 상대방 계좌번호를 입력하세요 => ";
	cin >> accountTmp;
	if(strcmp(accountTmp, accountNum) == 0) {	//입력받은 계좌번호와 자신의 계좌번호를 비교하여 일치한다면 에러문 출력
		cout << "│   현재 사용자의 계좌입니다. 자신에게 이체할 수 없습니다." << endl;
		return 0;
	}

	for(int i = 0; i < MAX_SIZE; i++) {
		if(strcmp(person[i].accountNum, accountTmp) == 0) {	//전체 사용자 중 존재하는 계좌번호이면 진행
			cout << "│   입력하신 계좌번호는 " << person[i].accountNum <<" 입니다.\n│   맞으면 1번, 틀리면 2번을 입력하세요 => ";
			cin >> checkNumber;
			if(checkNumber == 1) {	//계좌번호가 맞다고 1번을 입력하면 입금받을 상대방의 인덱스값 저장 후 반복문 종료
				a = i;
				break;
			}
			else if(checkNumber == 2) {	//계좌번호가 틀리다고 2번을 입력하면
				cout << "│   취소하셨습니다.\n│   다시 실행해주세요." << endl;
				return 0;		//계좌이체금액 0원으로 반환하여 차액 없게 반환
			}
			else {
				cout << "│   잘못 입력하셨습니다. 다시 실행해주세요." << endl;
				i--;
				continue;
			}
		}
		a = i;	//전체 사용자 중 존재하는 계좌번호가 없으면 MAX_SIZE - 1 만큼의 값을 a에 대입
	}
	if(a == (MAX_SIZE - 1)) {	//a값이 MAX_SIZE - 1 이면 상대방 계좌번호가 존재하지 않으므로 에러문 출력
		cout << "│   이체 될 계좌번호가 존재하지 않습니다.\n│   상대방 계좌번호를 확인하세요.\n";
		return 0;		//계좌이체금액 0원으로 차액 없게 반환
	}
	
	cout << "│   비밀번호를 입력하세요 => ";
	cin >> checkPw;

	if((strcmp(pw,checkPw)) == 0) {	//입력받은 비밀번호와 사용자 비밀번호가 일치한다면
		cout << "│   이체할 금액을 입력하세요.\n│   (최대 100,000,000원) => ";
		cin >> transMoney;
		if(transMoney > balance)		//입력받은 이체금액이 잔액보다 많을 때 에러문 출력
			cout << "│   잔액이 부족합니다 !! 잔액을 확인하세요." << endl;
		else if(transMoney > 100000000)		//입력받은 이체금액이 1억원 이상이면 에러문 출력
			cout << "│   100,000,000원 이상 이체할 수 없습니다 !!\n";
		else if(transMoney < 0)				//입력받은 이체금액이 0원 이하이면 에러문 출력
			cout << "│   0원 이하 이체할 수 없습니다 !!\n";
		else {
			cout << "│   이체 할 사용자 계좌번호를 입력하세요 => ";
			cin >> checkAccount;
			if(strcmp(checkAccount, accountNum) == 0) {	//사용자의 계좌번호가 일치하는지 2차확인 후 일치한다면
				person[a].balance += transMoney;	//상대방의 계좌에 계좌이체금액만큼 추가
				cout << "│   정상적으로 이체가 완료되었습니다." << endl;
				return balance -= transMoney;	//계좌이체금액을 사용자 잔액에서 차감
			}
			else
				cout << "│   사용자의 계좌번호가 틀립니다.\n│   계좌번호를 확인하세요." << endl;
		}
	}
	else
		cout << "│   비밀번호가 일치하지 않습니다 !!\n│   비밀번호를 확인하세요." << endl;
	return 0;
};

void accountInfo::checkInfo() {
	if(*name == NULL) {	//현재 아무 사용자도 선택되어있지 않으면 에러출력
		cout << "│   계좌가 존재하지 않습니다.\n│   먼저 사용자 등록을 하세요.\n";
		return;
	}
	cout << "│      ## 계좌 정보를 확인합니다... ##" << endl;
	cout << "│   사용자 이름 : " << name << "\n│   계좌번호 : " << accountNum << "\n│   잔액 : " << balance << "원" << endl;
};

void accountInfo::checkInfo(int num) {
	if(*name == NULL) {	//현재 아무 사용자도 선택되어있지 않으면 에러출력
		cout << "│   계좌가 존재하지 않습니다.\n│   먼저 사용자 등록을 하세요.\n";
		return;
	}
	while(1) {
		cout << "│   계좌정보를 확인하시려면 1번,\n│   잔액을 확인하시려면 2번을\n│   입력하세요 => ";
		cin >> num;
		if(num == 1) {
			cout << "│      ## 계좌 정보를 확인합니다... ##" << endl;
			cout << "│   " << name << "님의 계좌번호는\n│   " << accountNum << " 입니다." << endl;
			break;
		}
		else if(num == 2) {
			cout << "│      ## 계좌 정보를 확인합니다... ##" << endl;
			cout << "│   " << name << "님의 잔액은\n│   " << balance << "원 입니다." << endl;
			break;
		}
		else
			cout << "│   번호를 잘못 입력하셨습니다." << endl;
	}
};