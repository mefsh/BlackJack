#include "MenuConsoleController.h"
#include <iostream>


MenuConsoleController::MenuConsoleController()
{
}


MenuConsoleController::~MenuConsoleController()
{
}

void MenuConsoleController::executeBet(User& user)
{
	int value = 0;
	std::cin >> value;
	while (value > user.getMoney())
		std::cin >> value;
	user.setBetValue(value);
}

void MenuConsoleController::executeHit(User& user)
{
	user.setDecision(BJ::HIT);
}

void MenuConsoleController::executeStand(User& user)
{
	user.setDecision(BJ::STAND);
}

void MenuConsoleController::executeInsurance(User& user)
{
	user.setInsurance(true);
}

bool MenuConsoleController::getInsuranceAskResponse()
{
	char responseChar;
	std::cin >> responseChar;
	while (responseChar != 'y' &&
		responseChar != 'Y' &&
		responseChar != 'n' &&
		responseChar != 'N')
		std::cin >> responseChar;
	if (responseChar == 'y' ||
		responseChar == 'Y')
		return true;
	return false;
}

BJ::UserDecision MenuConsoleController::getHitStandResponse()
{
	int response = 0;
	std::cin >> response;
	while (response != 1 &&
		response != 2)
		std::cin >> response;
	if (response == 1)
		return BJ::HIT;
	return BJ::STAND;
}

void MenuConsoleController::makePause()
{
	system("pause>nul");
}
