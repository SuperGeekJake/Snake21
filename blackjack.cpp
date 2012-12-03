#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

// Classes
#include "hand.cpp"

/**
 * Outputs to console the current cards of the player and house
 * @param hide True outputs a unknown card for the house
 */
void displayHands(bool hide);

/**
 * Blackjack Game
 * @return Ends program
 */
int main() {
	// Game loop ends if it == 'n'
	char cont = 'y';
	// House's hit limit
	const int HITLIMIT = 17;
	// Max score without busting
	const int MAXSCORE = 21;
	//Hit or Stand message
	const string HSMESG = "Hit or Stand?(y/n): ";

	/**
	 * Main game loop
	 */
	while (cont == 'y') {
		// Single Round
		// =======================================
		yHand.dealCard(2);
		hHand.dealCard(1);

	 	displayHands(true);
	 	
	 	char hit = 'n';
	 	cout << HSMESG;
	 	cin >> hit;

	 	// Deal additional cards to player
	 	while (hit == 'y') {
	 		yHand.dealCard(1);

	 		displayHands(true);

	 		if (yHand.getScore() > MAXSCORE) {
	 			break;
	 		} else {
	 			cout << HSMESG;
		 		cin >> hit;
	 		}
	 	}

	 	// Deal cards to house as long as score is less than HITLIMIT
	 	do {
	 		hHand.dealCard(1);
	 	}while (hHand.getScore() < HITLIMIT);

	 	// Save final scores to reduce calls to function Hand::getScore()
	 	int yHandScore = yHand.getScore();
	 	int hHandScore = hHand.getScore();

	 	if (yHandScore > 21) {
	 		cout << "You busted, sorry." << endl;
	 	} else if (hHandScore > 21) {
	 		displayHands(false);
	 		cout << "You won, house busted!" << endl;
	 	} else if (yHandScore < hHandScore) {
	 		displayHands(false);
	 		cout << "The house won, sorry." << endl;
	 	} else if (yHandScore > hHandScore) {
	 		displayHands(false);
	 		cout << "You won, well played!" << endl;
	 	} else {
	 		displayHands(false);
	 		cout << "You tied the house." << endl;
	 	}

	 	// =======================================
	 	// End of Single Round
	 	
	 	// Remove cards from objects' cards vector in case of another hand
	 	yHand.resetHand();
	 	hHand.resetHand();
	 	cout << "Want to play another hand?(y/n): ";
	 	// Repeat game loop?
	 	cin >> cont;
	}
	
	return 0;
}

void displayHands(bool hide) {
	// Display your cards and score
	cout << "Your Hand: ";
 	yHand.displayHand();
 	cout << "= " << yHand.getScore() << endl;
 	// Display house's cards and score
 	cout << "House Hand: ";
 	hHand.displayHand();
 	// Keep house's 2nd card hidden until player is done hitting
 	if (hide == true) {
 		cout << "Unkown(?) = " << hHand.getScore() << endl;
 	}
 	else {
 		cout << "= " << hHand.getScore() << endl;
 	}
}
