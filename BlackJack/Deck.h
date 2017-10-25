#pragma once
#ifndef BJ_DECK
#define BJ_DECK

#include <vector>
#include "Cards.h"

class Deck
{
	bool deckFilling_;
	int deckRepetition_;
	std::vector<BJ::Cards> stackArray_;
protected:
	friend class Croupier;
	int takeTopCard();
public:
	Deck(bool = true, int = 8);
	virtual ~Deck();

	void createNewDeck();
	void randomShuffleDeck();
	void fillDeckIfEmpty();

	int getDeckSize() const;
};

#endif
