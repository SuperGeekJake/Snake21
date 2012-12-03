class Hand {
	vector<int> cards;
public:
	void dealCard(int amount);
	void displayHand();
	int getScore();
	string getSuite(int i);
	void resetHand();

}yHand, hHand;

void Hand::dealCard(int amount) {
	// Intialize random seed with current time
	srand (time(NULL));
	// Number of cards in a deck
	const int DECK = 52;
	int card;
	// Deal cards to someone up to the 'amount' parameter
	for (int i=0;i<amount;i++) {
		// Set card to random number out of DECK
		card = rand()%DECK+1;
		// Add card(int) to hand(vector)
		cards.push_back(card);
	}
}

void Hand::displayHand() {
	for (unsigned int i=0;i<cards.size();i++) {
		if (cards[i]%13 == 0) {
			cout << "King";
		}
		else if (cards[i]%13 == 12) {
			cout << "Queen";
		}
		else if (cards[i]%13 == 11) {
			cout << "Jack";
		}
		else if (cards[i]%13 == 1) {
			cout << "Ace";
		}
		else {
			cout << cards[i]%13;
		}
		cout << "(" << getSuite(i) << ") ";
	}
}

int Hand::getScore() {
	int total = 0;
	for (unsigned int i=0;i<cards.size();i++) {
		if (cards[i]%13 == 0 or cards[i]%13 > 10) {
			total += 10;
		}
		else if (cards[i]%13 == 1) {
			total += 11;
		}
		else {
			total += cards[i]%13;
		}
	}
	return total;
}

string Hand::getSuite(int i) {
	if (cards[i]<14) {
		return "Spade";
	}
	else if (cards[i]<27) {
		return "Diamond";
	}
	else if (cards[i]<40) {
		return "Club";
	}
	else {
		return "Heart";
	}
}

void Hand::resetHand() {
	cards.resize(0);
}
