#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;


class Deck
{
private:
	Card _cards[52];
	bool _used_indecies[52];
public:
	Deck();
	void resetDeck();
	Card getNextCard();

};

#endif