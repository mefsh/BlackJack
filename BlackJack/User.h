#pragma once
#ifndef BJ_USER
#define BJ_USER

#include "Player.h"
#include "UserDecision.h"

class User :
	public Player
{
	int money_;
	int betValue_;
	bool insurance_;
	BJ::UserDecision userDecision_;

	friend class Croupier;
	void handleMoney(int money);

protected:
	int betMoney(int);

public:
	User(int value=5000);
	virtual ~User();

	void setBetValue(int betValue);
	void setDecision(BJ::UserDecision);
	void setInsurance(bool insurance);

	int getMoney() const;
	int getBetValue() const;
	bool getInsurance() const;

	BJ::UserDecision getDecision() const;
};

#endif
