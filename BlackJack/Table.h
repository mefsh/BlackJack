#pragma once
#ifndef BJ_TABLE
#define BJ_TABLE

#include "Deck.h"
#include "Results.h"
#include "Croupier.h"
#include "User.h"
#include "ViewConsole.h"
#include "MenuConsoleController.h"

class Table
{
	Deck eightDecks_;
	Croupier croupier_;
	User user_;
	ViewConsole viewConsole_;
	MenuConsoleController menuConsoleController_;

public:
	Table();
	~Table();
	void startGame();
};

#endif
