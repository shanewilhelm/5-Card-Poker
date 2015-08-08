#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <iostream>
#include <string>
using namespace std;

class Hand
{
private:
	Card _hand[5];
public:
	void sortHand();
	void addCard(int position, Card card);
	void clearHand();
	void removeCard(int position);
	void displayHand();
	Card highCard();
	Card getCard(int position);
	int getHandRankValue();
	string getHandRankName();
	int hasPair();
	int hasTwoPair();
	int hasThreeOfAKind();
	bool hasStraight();
	bool hasFlush();
	bool hasFullHouse();
	bool hasFourOfAKind();
};




#endif