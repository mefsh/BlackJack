#include "Table.h"
#include <ctime>
#include <cstdlib>

Table::Table()
{
	srand(unsigned(time(nullptr)));
	eightDecks_.createNewDeck();
	eightDecks_.randomShuffleDeck();
}


Table::~Table()
{
}

void Table::startGame()
{
	while (user_.getMoney() > 0 && eightDecks_.getDeckSize() > 0)
	{
		//Clearing all
		croupier_.clearHand();
		user_.clearHand();
		user_.setInsurance(false);
		viewConsole_.clearView();
		croupier_.firstHandingOut(user_, eightDecks_);

		//Show info
		viewConsole_.showPlayerName(user_);
		viewConsole_.showUserMoney(user_);
		menuConsoleController_.executeBet(user_);
		viewConsole_.showPlayerCards(user_);
		viewConsole_.showPlayerPoints(user_);
		viewConsole_.makeLine();

		viewConsole_.showPlayerName(croupier_);
		viewConsole_.showPlayerCards(croupier_);
		viewConsole_.makeLine();

		const BJ::Results result = croupier_.firstRoundBlackJackCheck(user_);

		if (result == BJ::BJWIN ||
			result == BJ::DRAW)
		{
			croupier_.handleBet(user_, result);
			viewConsole_.showPauseInfo("Press any key to continue..", result);
			menuConsoleController_.makePause();
			continue;
		}
		if (result == BJ::LETINSURANCE)
		{
			viewConsole_.showInsuranceAsk();
			if (menuConsoleController_.getInsuranceAskResponse())
				menuConsoleController_.executeInsurance(user_);
		}


		const BJ::Results blackJackUser = croupier_.checkIfBlackJack();
		if (blackJackUser == BJ::LOSE)
		{
			if (user_.getInsurance())
			{
				croupier_.handleBet(user_, BJ::DRAW);
				viewConsole_.showPauseInfo("Press any key to continue..", BJ::LOSE);
				menuConsoleController_.makePause();
			}
			else
			{
				croupier_.handleBet(user_, BJ::LOSE);
				viewConsole_.showPauseInfo("Press any key to continue..", BJ::LOSE);
				menuConsoleController_.makePause();
			}
			continue;
		}


		viewConsole_.showHitStandMenu();
		BJ::UserDecision userDecision = menuConsoleController_.getHitStandResponse();
		while (userDecision == BJ::HIT && user_.calculateCurrentPoints() < 21)
		{
			croupier_.handOutOneCard(user_, eightDecks_);

			viewConsole_.clearView();

			//Show info
			viewConsole_.showPlayerName(user_);
			viewConsole_.showUserMoney(user_);
			viewConsole_.showPlayerCards(user_);
			viewConsole_.showPlayerPoints(user_);
			viewConsole_.makeLine();

			viewConsole_.showPlayerName(croupier_);
			viewConsole_.showPlayerCards(croupier_);
			viewConsole_.makeLine();
			viewConsole_.showHitStandMenu();

			if (user_.calculateCurrentPoints() >= 21) break;
			userDecision = menuConsoleController_.getHitStandResponse();
		}

		if (user_.calculateCurrentPoints() > 21)
		{
			croupier_.handleBet(user_, BJ::LOSE);
			viewConsole_.showPauseInfo("Press any key to continue..", BJ::LOSE);
			menuConsoleController_.makePause();
			continue;
		}

		while (croupier_.calculateCurrentPoints() < 17)
		{
			croupier_.handOutOneCard(croupier_, eightDecks_);
		}
		//////////////////////////
		viewConsole_.clearView();
		//Show info
		viewConsole_.showPlayerName(user_);
		viewConsole_.showUserMoney(user_);
		viewConsole_.showPlayerCards(user_);
		viewConsole_.showPlayerPoints(user_);
		viewConsole_.makeLine();

		viewConsole_.showPlayerName(croupier_);
		viewConsole_.showPlayerCards(croupier_, true);
		viewConsole_.showPlayerPoints(croupier_);
		viewConsole_.makeLine();
		///////////////////////////
		const int croupierResult = croupier_.calculateCurrentPoints();
		const int userResult = user_.calculateCurrentPoints();
		if (croupierResult > 21)
		{
			croupier_.handleBet(user_, BJ::WIN);
			viewConsole_.showPauseInfo("Press any key to continue..", BJ::WIN);
		}
		else if (croupierResult == userResult)
		{
			croupier_.handleBet(user_, BJ::DRAW);
			viewConsole_.showPauseInfo("Press any key to continue..", BJ::DRAW);
		}
		else
		{
			if (croupierResult > userResult)
			{
				croupier_.handleBet(user_, BJ::LOSE);
				viewConsole_.showPauseInfo("Press any key to continue..", BJ::LOSE);
			}
			else
			{
				croupier_.handleBet(user_, BJ::WIN);
				viewConsole_.showPauseInfo("Press any key to continue..", BJ::WIN);
			}
		}
		menuConsoleController_.makePause();
	}
	viewConsole_.showOutOfMoneyInfo();
	menuConsoleController_.makePause();
}
