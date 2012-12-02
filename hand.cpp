class Hand {
	vector<int> cards;
public:
	void dealCard(int amount);
	void displayHand();
	int getScore();
}yHand, hHand;

void Hand::dealCard(int amount) {
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
	for (int i=0;i<cards.size();i++) {
		cout << cards[i] << endl;
	}
}

int Hand::getScore() {
	int total = 0;
	for (int i=0;i<cards.size();i++) {
		// if its a face card, value should be set to 10
		if (cards[i]%13 == 0 or cards[i]%13 > 10) {
			total += 10;
		}
		// What if it's an ace?
		else if (cards[i]%13 == 1) {
			total += 11;
		}
		// Otherwise, we just want its number value
		else {
			total += cards[i]%13;
		}
	}
	return total;
}
