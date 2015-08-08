#include "Hand.h"

//Sorts the hand from low to high based first on rank, then on suit rank.
void Hand::sortHand()
{
	Card temp;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ( _hand[j].getRankValue() > _hand[j+1].getRankValue() )
			{
				temp = _hand[j+1];
				_hand[j+1] = _hand[j];
				_hand[j] = temp;
			}
			else if ( _hand[j].getRankValue() == _hand[j+1].getRankValue() )
			{
				if ( _hand[j].getSuitValue() > _hand[j+1].getSuitValue() )
				{
					temp = _hand[j+1];
					_hand[j+1] = _hand[j];
					_hand[j] = temp;
				}
			}
		}
	}
}
void Hand::addCard(int position, Card card)
{
	_hand[position] = card;
}
void Hand::clearHand()
{
	for (int i = 0; i < 5; i++)
	{
		_hand[i] = Card(); /*** Make this a 'NULL' card instead? ***/
	}
}
void Hand::removeCard(int position)
{
	_hand[position] = Card(); /*** Make this a 'NULL' card instead? ***/
}
void Hand::displayHand()
{
	for (int i = 0; i < 5; i++)
	{
		cout << i+1 << ". " << _hand[i].getRankName() << " of " << _hand[i].getSuitName() << endl;
	}

	cout << endl;
}
Card Hand::highCard()
{
	return _hand[4];
}
Card Hand::getCard(int position)
{
	return _hand[position];
}
//Returns the rank of the hand. 0 is the lowest (a high card) and 8 is the highest(straight flush).
int Hand::getHandRankValue()
{
	if (hasStraight() == true && hasFlush() == true)
	{
		return 8;
	}
	else if (hasFourOfAKind() == true)
	{
		return 7;
	}
	else if (hasFullHouse() == true)
	{
		return 6;
	}
	else if (hasFlush() == true)
	{
		return 5;
	}
	else if (hasStraight() == true)
	{
		return 4;
	}
	else if (hasThreeOfAKind() != -1)
	{
		return 3;
	}
	else if (hasTwoPair() != -1)
	{
		return 2;
	}
	else if (hasPair() != -1)
	{
		return 1;
	}
	else //High card
	{
		return 0;
	}
	
}
string Hand::getHandRankName()
{
	if (hasStraight() == true && hasFlush() == true)
	{
		return "Straight Flush";
	}
	else if (hasFourOfAKind() == true)
	{
		return "Four-of-a-Kind";
	}
	else if (hasFullHouse() == true)
	{
		return "Full House";
	}
	else if (hasFlush() == true)
	{
		return "Flush";
	}
	else if (hasStraight() == true)
	{
		return "Straight";
	}
	else if (hasThreeOfAKind() != -1)
	{
		return "Three-of-a-Kind";
	}
	else if (hasTwoPair() != -1)
	{
		return "Two Pair";
	}
	else if (hasPair() != -1)
	{
		return "Pair";
	}
	else //High card
	{
		return "High Card";
	}
	
}
//Returns rankValue of pair. -1 if no pair
int Hand::hasPair()
{
	for (int i = 0; i < 4; i++)
	{
		if ( _hand[i].getRankName() == _hand[i+1].getRankName() )
		{
			return _hand[i].getRankValue();
		}
	}

	//No Pair
	return -1;
}
//Returns position of card not in either pair. -1 if hasTwoPair == false
int Hand::hasTwoPair()
{
	for (int i = 0; i < 4; i++)
	{
		if ( _hand[i].getRankName() == _hand[i+1].getRankName() )
		{
			if (i >= 2)
			{
				return -1;
			}
			else
			{
				if ( _hand[2].getRankName() == _hand[3].getRankName() )
				{
					return 4;
				}
				else if ( _hand[3].getRankName() == _hand[4].getRankName() )
				{
					if ( _hand[0].getRankName() == _hand[1].getRankName() )
					{
						return 2;
					}
					else
					{
						return 0;
					}
				}
			}
		}
	}

	//Not even a pair.
	return -1;
}
/*
Returns -1 if no Three of Kind. 
Returns 0 if the first 2 cards can be discarded. 
Returns 1 if the end cards can be discarded. 
Returns 2 if the last 2 cards can be discarded.
*/
int Hand::hasThreeOfAKind()
{
	if ( _hand[0].getRankName() == _hand[1].getRankName() && _hand[1].getRankName() == _hand[2].getRankName() )
	{
		return 2;
	}
	else if ( _hand[1].getRankName() == _hand[2].getRankName() && _hand[2].getRankName() == _hand[3].getRankName() )
	{
		return 1;
	}
	else if ( _hand[2].getRankName() == _hand[3].getRankName() && _hand[3].getRankName() == _hand[4].getRankName() )
	{
		return 0;
	}
	else 
	{
		return -1;
	}
}
bool Hand::hasStraight()
{
	for (int i = 0; i < 4; i++)
	{
		if ( (_hand[i].getRankValue() + 1) == (_hand[i+1].getRankValue()) )
		{
			//Do nothing. So far, the cards form a straight.
		}
		else if ( i == 3 && ( (_hand[i].getRankValue() + 9) == (_hand[i+1].getRankValue()) ) )
		{
			//Ace is used as a low card, and the rest must be 2, 3, 4, and 5.
			return true;
		}
		else
		{
			return false;
		}
	}

	//Never disqualified as a straight, so it must be one.
	return true;
}
bool Hand::hasFlush()
{
	for (int i = 0; i < 4; i++)
	{
		if ( (_hand[i].getSuitName()) == (_hand[i+1].getSuitName()) )
		{
			//Do nothing. So far, the cards form a flush.
		}
		else
		{
			return false;
		}
	}

	//Never disqualified as a flush, so it must be one.
	return true;
}
bool Hand::hasFullHouse()
{
	if ( _hand[0].getRankName() == _hand[1].getRankName() &&  _hand[1].getRankName() == _hand[2].getRankName() )
	{
		if ( _hand[3].getRankName() == _hand[4].getRankName() )
		{
			return true;
		}
	}
	else if ( _hand[2].getRankName() == _hand[3].getRankName() && _hand[3].getRankName() == _hand[4].getRankName() )
	{
		if ( _hand[0].getRankName() == _hand[1].getRankName() )
		{
			return true;
		}
	}
	else 
	{
		return false;
	}
}
bool Hand::hasFourOfAKind()
{
	if ( _hand[0].getRankName() == _hand[1].getRankName() && _hand[1].getRankName() == _hand[2].getRankName() && _hand[2].getRankName() == _hand[3].getRankName() )
	{
		return true;
	}
	else if ( _hand[1].getRankName() == _hand[2].getRankName() && _hand[2].getRankName() == _hand[3].getRankName() && _hand[3].getRankName() == _hand[4].getRankName() )
	{
		return true;
	}
	else 
	{
		return false;
	}
}