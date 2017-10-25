#pragma once
#ifndef BJ_VIEW
#define BJ_VIEW

#include "Player.h"
#include "User.h"

class View
{
public:
	View(){};
	virtual ~View(){};

	virtual void showPlayerCards(Player& player, bool firstCroupierCard) = 0;
	virtual void showPlayerPoints(Player& player) = 0;
	virtual void showPlayerName(Player& player) = 0;
	virtual void showUserMoney(User& user) = 0;
	virtual void showHitStandMenu() = 0;
	virtual void showInsuranceAsk() = 0;
	virtual void showOutOfMoneyInfo() = 0;
	virtual void clearView() = 0;
};

#endif
