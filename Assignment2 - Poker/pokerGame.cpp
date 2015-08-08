#include "PokerGame.h"

void Poker::playGame()
{
	Deck myDeck;
	Hand playerHand;
	Hand computerHand;
	Card myCard;
	
	cout << "***   Welcome to Simple 5-Card Poker!!!   ***" << endl;

	for (int i = 0; i < 5; i++)
	{
		myCard = myDeck.getNextCard();
		playerHand.addCard(i, myCard);
	}
	playerHand.sortHand();

	cout << "The cards have been shuffled and you are delt:" << endl;
	playerHand.displayHand();

	string input = "";
	int position = 0;
	int i = 0;
	cout << "Which cards would you like to exchange? (Enter \"-1\" to Continue...)" << endl;
	do
	{
		cin >> input;
		try
		{
			position = stoi(input);
		}
		catch(...)
		{
			cout << "Invalid Input." << endl;
		}

		if (position <= 0 || position > 5)
		{
			if (position == -1)
			{
				//Do nothing
			}
			else
			{
			cout << "Invalid Input." << endl;
			}
		}
		else //position between 1 and 5
		{
			playerHand.removeCard( (position-1) );
			myCard = myDeck.getNextCard();
			playerHand.addCard( (position-1) , myCard);

			i++;
		}
	} while (position != -1 && i < 5);
	playerHand.sortHand();

	cout << "Your new cards are:" << endl;
	playerHand.displayHand();

	//End Player's Turn
	//Begin Computer's turn

	for (int i = 0; i < 5; i++)
	{
		myCard = myDeck.getNextCard();
		computerHand.addCard(i, myCard);
	}
	computerHand.sortHand();

	cout << endl << "The computer is delt the following cards:" << endl;
	computerHand.displayHand();


	cout << "The computer exchanges ";
	if (computerHand.hasFlush() == true || computerHand.hasFullHouse() == true || computerHand.hasFourOfAKind() == true)
	{
		//Discard nothing
		cout << "nothing." << endl;
	}
	else if (computerHand.hasTwoPair() != -1)
	{
		//Discard the one card that is not part of the two pair.
		int cardToRemove = computerHand.hasTwoPair();
		computerHand.removeCard(cardToRemove);

		myCard = myDeck.getNextCard();
		computerHand.addCard(cardToRemove, myCard);

		cout << "card " << cardToRemove + 1 << "." << endl;
	}
	else if (computerHand.hasThreeOfAKind() != -1)
	{
		int frontMiddleOrBack = computerHand.hasThreeOfAKind();
		if (frontMiddleOrBack == 0)
		{
			computerHand.removeCard(0);
			myCard = myDeck.getNextCard();
			computerHand.addCard(0, myCard);

			computerHand.removeCard(1);
			myCard = myDeck.getNextCard();
			computerHand.addCard(1, myCard);

			cout << "cards 1 and 2." << endl;
		}
		else if (frontMiddleOrBack == 1)
		{
			computerHand.removeCard(0);
			myCard = myDeck.getNextCard();
			computerHand.addCard(0, myCard);

			computerHand.removeCard(4);
			myCard = myDeck.getNextCard();
			computerHand.addCard(4, myCard);

			cout << "cards 1 and 5." << endl;
		}
		else //frontMiddleOrBack == 2
		{
			computerHand.removeCard(3);
			myCard = myDeck.getNextCard();
			computerHand.addCard(3, myCard);

			computerHand.removeCard(4);
			myCard = myDeck.getNextCard();
			computerHand.addCard(4, myCard);

			cout << "cards 4 and 5." << endl;
		}
	}
	else if (computerHand.hasPair() != -1)
	{
		int rankValue = computerHand.hasPair();
		int cardCounter = 0;

		cout << "cards ";
		
		for (int i = 0; i < 5; i++)
		{
			myCard = computerHand.getCard(i);
			if (myCard.getRankValue() == rankValue)
			{
				//Do nothing (That's part of the pair)
			}
			else
			{
				computerHand.removeCard(i);
				myCard = myDeck.getNextCard();
				computerHand.addCard(i, myCard);

				cardCounter++;
				if (cardCounter >= 3)
				{
					cout << "and " << i+1 << "." << endl;
				}
				else 
				{
					cout << i+1 << ", ";
				}
			}
		}
	}
	else //Nothing special in hand
	{
		cout << "all their cards." << endl;

		for (int i = 0; i < 5; i++)
		{
			computerHand.removeCard(i);
			myCard = myDeck.getNextCard();
			computerHand.addCard(i, myCard);
		}
	}

	computerHand.sortHand();
	computerHand.displayHand();

	//End Computer's Turn
	//Begin Winner Check

	cout << "You have a " << playerHand.getHandRankName() << "." << endl;
	cout << "The computer has a " << computerHand.getHandRankName() << "." << endl;

	if ( playerHand.getHandRankValue() > computerHand.getHandRankValue() )
	{
		cout << "You win!" << endl;
	}
	else if ( playerHand.getHandRankValue() < computerHand.getHandRankValue() )
	{
		cout << "The computer wins." << endl;
	}
	else //Tie (...at least enough for this assignment)
	{
		if (playerHand.getHandRankValue() == 0) //Tied with only a high card
		{
			Card computerHighCard = computerHand.highCard();
			Card playerHighCard = playerHand.highCard();

			if (playerHighCard.getRankValue() > computerHighCard.getRankValue())
			{
				cout << "You win!" << endl;
			}
			else if (playerHighCard.getRankValue() < computerHighCard.getRankValue())
			{
				cout << "The computer wins." << endl;
			}
			else //Same face, so compare suit
			{
				if (playerHighCard.getSuitValue() > computerHighCard.getSuitValue())
				{
					cout << "You win!" << endl;
				}
				else if (playerHighCard.getSuitValue() < computerHighCard.getSuitValue())
				{
					cout << "The computer wins." << endl;
				}
			}
		}
		else//Tied with something other than a high card, such as both having a pair. Too complex for this assignment.
		{
			cout << "You tied." << endl;
		}
	}
}