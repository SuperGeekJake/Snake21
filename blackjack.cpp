#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>
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
	int wins;
	int losses;

	char newPlayer;
	cout << "Are you a new player?(y/n): ";
	cin >> newPlayer;
	if (newPlayer == 'y') {
		wins = 0;
		losses = 0;
	}
	else {
		// Read scores from file
		ifstream fin;
	    fin.open("scores.txt");
	    if (fin.fail()) {
	        cout << "Input file opening failed." << endl;
	        exit(-1);
	    }
	    fin >> wins >> losses;
	    fin.close();
	}

	// Intialize random seed with current time
	srand (time(NULL));

	// House's hit limit
	const int HITLIMIT = 17;
	// Max score without busting
	const int MAXSCORE = 21;
	//Hit or Stand message
	const string HSMESG = "Hit or Stand?(y/n): ";

	char cont;
	/**
	 * Main game loop
	 */
	do {
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
	 		cout << "You busted, sorry.";
	 		losses++;
	 		cout << endl;
	 	} else {
	 		displayHands(false);
	 		if (hHandScore > 21) {
		 		cout << "You won, house busted!";
		 		wins++;
		 	} else if (yHandScore < hHandScore) {
		 		cout << "The house won, sorry.";
		 		losses++;
		 	} else if (yHandScore > hHandScore) {
		 		cout << "You won, well played!";
		 		wins++;
		 	} else {
		 		cout << "You tied the house.";
		 	}
		 	cout << endl;
	 	}

	 	// =======================================
	 	// End of Single Round
	 	
	 	// Remove cards from objects' cards vector in case of another hand
	 	yHand.resetHand();
	 	hHand.resetHand();

	 	cout << "Wins: " << wins << " Losses: " << losses << endl;
	 	cout << "Want to play another hand?(y/n): ";
	 	// Repeat game loop?
	 	cin >> cont;

	} while (cont == 'y');

	ofstream fout;
    fout.open("scores.txt");
    if (fout.fail()) {
        cout << "Output file opening failed.\n";
        exit(-1);
    }
    fout << wins << endl
         << losses << endl;
    fout.close();
	
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
