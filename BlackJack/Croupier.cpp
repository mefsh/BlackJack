#include "Croupier.h"
#include "Results.h"


Croupier::Croupier()
{
}


Croupier::~Croupier()
{
}

void Croupier::handOutOneCard(Player& player, Deck& deck)
{
	deck.fillDeckIfEmpty();
	BJ::Cards card = static_cast<BJ::Cards>(deck.takeTopCard());
	player.putCardToHand(card);
}

void Croupier::firstHandingOut(Player& player, Deck& deck)
{
	for (int i = 0; i < 4; i++)
	{
		deck.fillDeckIfEmpty();
		BJ::Cards card = static_cast<BJ::Cards>(deck.takeTopCard());
		if (i % 2 == 0)
			player.putCardToHand(card);
		else
			putCardToHand(card);
	}
}

void Croupier::handleBet(User& user, BJ::Results matchResult)
{
	int value;
	switch (matchResult)
	{
	case BJ::WIN:
		value = user.getBetValue();
		break;
	case BJ::LOSE:
		value = -(user.getBetValue());
		break;
	case BJ::DRAW:
		value = 0;
		break;
	case BJ::BJWIN:
		value = static_cast<int>(user.getBetValue() * 1.5);
		break;
	default:
		value = 0;
	}
	user.handleMoney(value);
}

BJ::Results Croupier::firstRoundBlackJackCheck(User& user)
{
	const int points = user.calculateCurrentPoints();
	if (points == 21)
	{
		if (cardsInHand_[1] == BJ::ACE)
		{
			if (calculateCurrentPoints() == 21)
				return BJ::DRAW;
		}
		else
		{
			return BJ::BJWIN;
		}
	}
	else
	{
		if (cardsInHand_[1] == BJ::ACE)
		{
			return BJ::LETINSURANCE;
		}
	}
	return BJ::NOTHING;
}

BJ::Results Croupier::checkIfBlackJack()
{
	if (cardsInHand_[1] == BJ::ACE)
	{
		if (calculateCurrentPoints() == 21)
			return BJ::LOSE;
	}
	return BJ::NOTHING;
}
