#include "User.h"


void User::handleMoney(int money)
{
	money_ += money;
}

int User::betMoney(int value)
{
	if (money_ < value)
		return 0;
	money_ -= value;
	return value;
}

User::User(int value) : betValue_(0), insurance_(false), userDecision_(BJ::STAND)
{
	money_ = value;
}


User::~User()
{
}

void User::setBetValue(int betValue)
{
	betValue_ = betValue;
}

void User::setDecision(BJ::UserDecision userDecision)
{
	userDecision_ = userDecision;
}

void User::setInsurance(bool insurance)
{
	insurance_ = insurance;
}

int User::getMoney() const
{
	return money_;
}

int User::getBetValue() const
{
	return betValue_;
}

bool User::getInsurance() const
{
	return insurance_;
}

BJ::UserDecision User::getDecision() const
{
	return userDecision_;
}
