class hand {
	vector<int> cards;
public:
	void dealCard(int amount);
	void displayHand();
}yHand, hHand;

void dealCard(unsigned amount) {
	// Deal cards to someone up to the 'amount' parameter
	for (unsigned i=0;i<amount;i++) {
		// Number of cards in a deck
		const int DECK = 52;
		// Set card to random number out of DECK
		int card = rand()%DECK+1;
		// Add card(int) to hand(vector)
		cards.push_back(card);
	}
}

void displayHand() {
	for (unsigned i=0;i<cards.size();i++) {
		cout << cards[1] << endl;
	}
}
