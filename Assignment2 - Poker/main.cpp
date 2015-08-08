#include "Hand.h"
#include "Card.h"
#include "Deck.h"
#include "PokerGame.h"

#include <iostream>
#include <string>

int main(void)
{
	while (true)
	{
		//Clear command prompt - Windows only
		system("cls");

		Poker::playGame();

		//Wait to see results - Windows only
		system("pause");
	};

	//Will never actually be reached
	return 0;
}