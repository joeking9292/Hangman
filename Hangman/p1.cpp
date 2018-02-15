// Joe Noonan
// p1.cpp
// Purpose: This file runs the main function of the hangman project.

//Input: The input are things like the file of words and also the user's guesses
// and choices for running the game and playing again.
//Process: The computer uses the functions written in hangman.cpp file to run
// the game and also uses the Hangman class to make the game run and store data.
//Output: The outputs are things like user prompts, game displays, game
// statistics, and error messages.


#include <iostream>
#include <string>
#include "hangman.h"
using namespace std;

const string WORD_FILE = "/home/fac/lundeenk/submit/17fq1430/files/p1input.dat";

int main() {
	Hangman game;
	if (game.initializeFile(WORD_FILE))
		cout << "file loaded OK";
	else
		cout << "file not loaded";
	cout << endl << endl;

	bool doneWithGame = false;
	for (int i = 0; !doneWithGame; i++) {
		if (!game.newWord())
			cout << "newWord failed" << endl;

		bool done = false;
		bool won = false;
		char letter;
		while (!done) {
			game.displayGame();
			cout << "What letter? ";
			cin >> letter;
			if (!game.guess(toupper(letter), done, won)) {
				cout << letter << " was already guessed or is not allowed";
				cout << endl;
			}
		}
		game.revealWord();
		if (won)
			cout << "You won!";
		char userInput;
		cout << endl << "Would you like to continue to play, y or n?";
		cin >> userInput;
		if (userInput == 'n') {
			doneWithGame = true;
			cout << "Goodbye" << endl;
		}
		game.reset();
	}
	game.displayStatistics();
}