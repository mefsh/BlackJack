#pragma once

#ifndef BJ_MENUCONSOLECONTROLLER
#define BJ_MENUCONSOLECONTROLLER

#include "MenuController.h"


class MenuConsoleController :
	public MenuController
{
public:
	MenuConsoleController();
	virtual ~MenuConsoleController();
	void executeBet(User& user) override;
	void executeHit(User& user) override;
	void executeStand(User& user) override;
	void executeInsurance(User& user) override;
	bool getInsuranceAskResponse() override;

	BJ::UserDecision getHitStandResponse() override;

	static void makePause();
};

#endif
