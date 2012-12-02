#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

// Classes
#include "hand.cpp"

/**
 * Blackjack Game
 * @return Ends program
 */
int main() {
	// Intialize random seed with current time
	srand (time(NULL));
	// const int winValue = 21;
	// Game loop ends if it's 'y'
	char continue = 'y';

	while (continue == 'y') {
		// first hand
		yHand.dealCard(2);
		hHand.dealCard(1);

		cout << "Your Hand: " << yHand.displayHand() << " = " << yHand.getScore() << endl;
	 	cout << "House Hand: " << hHand.displayHand() << "Unkown(?) = " << hHand.getScore() << endl;
	}
	
	return 0;
}
