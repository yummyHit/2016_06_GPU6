#ifndef SERVERATM_H
#define SERVERATM_H


class serverATM {
public:
	virtual void showMenu() = 0;
	virtual void checkInfo() = 0;
	virtual int searchInfo() {return 0;};
	virtual int insertInfo() {return 0;};
	virtual int depoInfo() = 0;
	virtual int transferInfo() {return 0;};
	virtual int checkID() = 0;
};

#endif