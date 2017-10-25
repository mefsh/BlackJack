#include "ViewConsole.h"
#include <iostream>
#include <string>
#include "User.h"


ViewConsole::ViewConsole()
{
}


ViewConsole::~ViewConsole()
{
}

void ViewConsole::showPlayerCards(Player& player, bool firstCroupierCard)
{
	std::vector<BJ::Cards> currentPlayer = player.getCards();
	std::vector<std::string> cardsArray;
	std::string cards[]
	{
		"Two",
		"Three",
		"Four",
		"Five",
		"Six",
		"Seven",
		"Eight",
		"Nine",
		"Ten",
		"Jack",
		"Lady",
		"King",
		"Ace"
	};
	bool state = false;
	std::cout << "Cards: ";
	for (auto i : currentPlayer)
	{
		if (!firstCroupierCard)
		{
			if (typeid(player).name() == typeid(Croupier).name())
				if (state == false)
				{
					state = true;
					continue;
				}
		}
		std::cout << cards[i - 2] << " ";
	}
	std::cout << std::endl;
}

void ViewConsole::showPlayerPoints(Player& player)
{
	std::cout << "Points: " << player.calculateCurrentPoints() << std::endl;
}

void ViewConsole::showPlayerName(Player& player)
{
	if (typeid(player).name() == typeid(User).name())
		std::cout << "[Player]" << std::endl;
	else
		std::cout << "[Croupier]" << std::endl;
}

void ViewConsole::showUserMoney(User& user)
{
	std::cout << "Money: " << user.getMoney() << std::endl;
}


void ViewConsole::showHitStandMenu()
{
	std::cout << "[Hit] 1 ; [Stand] 2" << std::endl;
}

void ViewConsole::showInsuranceAsk()
{
	std::cout << "Do you want insurance? [Y/N]: ";
}

void ViewConsole::showOutOfMoneyInfo()
{
	std::cout << "Sorry, you're out of money!" << std::endl << "GAME OVER!" << std::endl;
	std::cout << "Press any key to close the application.." << std::endl;
}

void ViewConsole::clearView()
{
	system("cls");
}


void ViewConsole::makeLine()
{
	std::cout << "---------------------------------" << std::endl;
}

void ViewConsole::showPauseInfo(std::string text, BJ::Results result)
{
	switch (result)
	{
	case BJ::WIN:
		std::cout << "You win! [Reward 1:1]" << std::endl;
		break;
	case BJ::LOSE:
		std::cout << "You lose!" << std::endl;
		break;
	case BJ::DRAW:
		std::cout << "DRAW! [Getting back your bet]" << std::endl;
		break;
	case BJ::BJWIN:
		std::cout << "BlackJack! [Reward 1.5:1]" << std::endl;
		break;
	default: ;
	}
	std::cout << text << std::endl;
}
