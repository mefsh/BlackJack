#pragma once
#ifndef BJ_PLAYER
#define BJ_PLAYER
#include <vector>
#include "Deck.h"

class Player
{
protected:
	std::vector<BJ::Cards> cardsInHand_;
public:
	Player();
	virtual ~Player();

	virtual void putCardToHand(BJ::Cards);
	virtual void clearHand();

	virtual std::vector<BJ::Cards> getCards();
	virtual int calculateCurrentPoints();
};

#endif
