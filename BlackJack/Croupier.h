#pragma once
#ifndef BJ_CROUPIER
#define BJ_CROUPIER
#include "Player.h"
#include "User.h"
#include "Results.h"

class Croupier
	: public Player
{
public:
	Croupier();
	virtual ~Croupier();

	void handOutOneCard(Player& player, Deck& deck);
	void firstHandingOut(Player& player, Deck& deck);
	void handleBet(User& user, BJ::Results matchResult);

	BJ::Results firstRoundBlackJackCheck(User& user);
	BJ::Results checkIfBlackJack();
};

#endif
