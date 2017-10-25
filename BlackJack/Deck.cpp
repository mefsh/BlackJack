#include "Deck.h"
#include <algorithm>

Deck::Deck(bool deckFilling, int deckRepetition) : deckFilling_(true), deckRepetition_(8)
{
	deckFilling_ = deckFilling;
	deckRepetition_ = deckRepetition;
}

Deck::~Deck()
{
}

int Deck::takeTopCard()
{
	int card = 0;
	if (stackArray_.size() > 0)
	{
		card = static_cast<int>(stackArray_.back());
		stackArray_.pop_back();
	}
	return card;
}

void Deck::createNewDeck()
{
	for (int i = 2; i <= 14; i++)
		stackArray_.insert(stackArray_.end(), deckRepetition_, static_cast<BJ::Cards>(i));
}

void Deck::randomShuffleDeck()
{
	random_shuffle(stackArray_.begin(), stackArray_.end());
}


void Deck::fillDeckIfEmpty()
{
	if (getDeckSize() <= 0)
	{
		createNewDeck();
		randomShuffleDeck();
	}
}


int Deck::getDeckSize() const
{
	return static_cast<int>(stackArray_.size());
}
