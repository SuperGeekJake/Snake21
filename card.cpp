class Card {
	int card;
public:
	Card();
	int getValue();
	string getSuite();
};

Card::Card() {
	// Number of cards in a deck
	const int DECK = 52;
	// Set card to random number out of DECK
	card = rand()%DECK+1;
}

int Card::getValue() {
	// if its a face card, value should be set to 10
	if (card%13 == 0 or card%13 > 10) {
		return 10;
	}
	// What if it's an ace?
	else if (card%13 == 1) {
		return 11;
	}
	// Otherwise, we just want its number value
	else {
		return card%13;
	}
}

string Card::getSuite() {
	if (card<14) {
		return "Spade";
	}
	else if (card<27) {
		return "Diamond";
	}
	else if (card<40) {
		return "Club";
	}
	else {
		return "Heart";
	}
}
