#include "Player.h"
#include <iostream>


Player::Player()
{
}


Player::~Player()
{
}

void Player::putCardToHand(BJ::Cards card)
{
	cardsInHand_.push_back(card);
}

void Player::clearHand()
{
	cardsInHand_.clear();
}

std::vector<BJ::Cards> Player::getCards()
{
	return cardsInHand_;
}

int Player::calculateCurrentPoints()
{
	int sum = 0;
	int aces = 0;
	for (unsigned int i = 0; i < cardsInHand_.size(); ++i)
	{
		if (static_cast<int>(cardsInHand_[i]) < 11)
			sum += static_cast<int>(cardsInHand_[i]);
		else if (static_cast<int>(cardsInHand_[i]) == 14)
		{
			if (sum + 11 <= 21)
			{
				sum += 11;
				aces++;
			}
			else
				sum += 1;
		}
		else
			sum += 10;

		if (sum > 21 && aces > 0)
		{
			int acesToSubtract = 0;
			for (int i = 0; i < aces; ++i)
			{
				if (sum > 21)
				{
					sum -= 10;
					acesToSubtract++;
				}
				else
					break;
			}
			aces -= acesToSubtract;
		}
	}
	return sum;
}
