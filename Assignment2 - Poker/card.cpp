#include "Card.h"

Card::Card(Suit_t suit, Rank_t rank)
{
	_suit = suit;
	_rank = rank;
}
Card::Card()
{
	_suit = Clubs;
	_rank = Two;
}
Suit_t Card::getSuit() const
{
	return _suit;
}
string Card::getSuitName() const
{
	switch (_suit)
	{
	case Clubs:
		return "Clubs";
	case Diamonds:
		return "Diamonds";
	case Hearts:
		return "Hearts";
	case Spades:
		return "Spades";
	}
}
int Card::getSuitValue() const
{
	return (int)_suit;
}
Rank_t Card::getRank() const
{
	return _rank;
}
int Card::getRankValue() const
{	
	return (int)_rank;
}
string Card::getRankName() const
{
	switch (_rank)
	{
	case Two: 
		return "Two";
	case Three: 
		return "Three";
	case Four:
		return "Four";
	case Five:
		return "Five";
	case Six:
		return "Six";
	case Seven:
		return "Seven";
	case Eight:
		return "Eight";
	case Nine:
		return "Nine";
	case Ten:
		return "Ten";
	case Jack:
		return "Jack";
	case Queen:
		return "Queen";
	case King:
		return "King";
	case Ace:
		return "Ace";
	}
}