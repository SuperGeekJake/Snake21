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
	// char endGame = 'n';
	yHand.dealCard(2);
	yHand.displayHand();

	// cout << "=======================================================\n" <<
	// 		"  XXXXX                  XX                XXX      X\n" <<
	// 		" X     X                  X               X   X   XXX\n" <<
	// 		" X                        X                   X     X\n" <<
	// 		" X       XX XX    XXXX    X  XX   XXXXX       X     X\n" <<
	// 		"  XXXXX   XX  X       X   X  X   X     X     X      X\n" <<
	// 		"       X  X   X   XXXXX   X X    XXXXXXX    X       X\n" <<
	// 		"       X  X   X  X    X   XXX    X         X        X\n" <<
	// 		" X     X  X   X  X    X   X  X   X     X  X         X\n" <<
	// 		"  XXXXX  XXX XXX  XXXX X XX   XX  XXXXX   XXXX  XXXXX\n" <<
	// 		"=======================================================\n" <<
	// 		"Simple Blackjack (21) by Jacob Williams\n" <<
	// 		"Gameplay:\n" <<
	// 		"> Single player\n" <<
	// 		"> Unlimited Decks\n" <<
	// 		"> Only allows for hit or stand\n" <<
	// 		"> House hits below 17\n" <<
	// 		"> No specialized rules\n" <<
	// 		"> No chips or money involved\n" <<
	// 		"=======================================================\n\n" <<
	// 		"Want to play a hand?(y/n): ";
	// cin >> endGame;
	// cout << endl;
	// while (endGame == 'y') {
		
	// 	newHand();

	// 	cout << "====================== New Hand =======================\n\n";
	// 	char stand = 'h';
	// 	while (stand == 'h') {
	// 		cout << "Your Hand: 10(Club) King(Diamond) = 20\n";
	// 		cout << "House Hand: 10(Club) King(Diamond) = 20\n\n";
	// 		cout << "Hit or Stand(h/s): ";
	// 		cin >> stand;
	// 	}
	// 	if (yScore > winValue) {
	// 		cout << "You busted, I'm sorry. Play another hand? (y/n): ";
	// 	} else if (yScore > hScore) {
	// 		cout << "You Won, that's great. Another hand?(y/n): ";
	// 	} else if (yScore < hScore) {
	// 		cout << "The house won, I'm sorry. Play another hand? (y/n): ";
	// 	} else {
	// 		cout << "You tied the house. Another hand?(y/n): ";
	// 	}
	// 	cin >> endGame;
	// 	cout << "\n";
	// }
	// cout << "Wins: / Losses: \n" <<
	// 		"=============XXXX Thanks for playing! XXXX=============\n";
	return 0;
}
