#pragma once
#ifndef BJ_VIEWCONSOLE
#define BJ_VIEWCONSOLE

#include "View.h"
#include <string>
#include "Results.h"

class ViewConsole :
	public View
{
public:
	ViewConsole();
	~ViewConsole();

	void showPlayerCards(Player& player, bool firstCroupierCard = false) override;
	void showPlayerPoints(Player& player) override;
	void showPlayerName(Player& player) override;
	void showUserMoney(User& user) override;
	void showHitStandMenu() override;
	void showInsuranceAsk() override;
	void showOutOfMoneyInfo() override;
	void clearView() override;


	static void makeLine();
	static void showPauseInfo(std::string, BJ::Results);
};

#endif
