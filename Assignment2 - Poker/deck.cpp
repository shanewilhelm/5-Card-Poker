#include "Deck.h"

Deck::Deck()
{
	srand( (unsigned)time(NULL) );
	resetDeck();
}
void Deck::resetDeck()
{
	//initialize _used_indecies
	for (int j = 0; j < 52; j++)
		{
			_used_indecies[j] = false;
		}
	
	for (int suit = Clubs; suit <= Spades; suit++)
	{				
		for (int rank = Two; rank <= Ace; rank++)
		{
			int r = 0;

			do
			{
				r = rand() % 52;
			} while (_used_indecies[r] == true);

			_cards[r] = Card((Suit_t)suit, (Rank_t)rank);
			_used_indecies[r] = true;
		}
	}
	
	//Initialize _used_indecies
	for (int j = 0; j < 52; j++)
	{
		_used_indecies[j] = 0;
	}
}
Card Deck::getNextCard()
{
	int i = 0;
	Card nextCard;

	while (_used_indecies[i] == true)
	{
		i++;
	}
	
	nextCard = _cards[i];
	_used_indecies[i] = true;

	return nextCard;
}