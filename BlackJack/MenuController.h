#pragma once
#ifndef BJ_MENUCONTROLLER
#define BJ_MENUCONTROLLER

#include "User.h"

class MenuController
{
public:
	MenuController(){};
	virtual ~MenuController(){};
	virtual void executeBet(User& user) = 0;
	virtual void executeHit(User& user) = 0;
	virtual void executeStand(User& user) = 0;
	virtual void executeInsurance(User& user) = 0;
	virtual bool getInsuranceAskResponse() = 0;

	virtual BJ::UserDecision getHitStandResponse() = 0;
};

#endif
