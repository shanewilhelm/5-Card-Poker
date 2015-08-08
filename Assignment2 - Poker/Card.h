#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
using namespace std;

typedef enum Suit_t
{
	Clubs, 
	Diamonds,
	Hearts,
	Spades
};
typedef enum Rank_t
{
	Two = 2,
	Three, 
	Four,
	Five,
	Six, 
	Seven, 
	Eight, 
	Nine, 
	Ten, 
	Jack, 
	Queen, 
	King, 
	Ace
};

class Card
{
private:
	Suit_t _suit;
	Rank_t _rank;
public:
	Card(Suit_t suit, Rank_t rank);
	Card();
	Suit_t getSuit() const;
	string getSuitName() const;
	int getSuitValue() const;
	Rank_t getRank() const;
	int getRankValue() const;
	string getRankName() const;
};

#endif