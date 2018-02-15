// Joe Noonan
// hangman.cpp
// Purpose: The purpose of this file is to be where all the functions defined
// in the hangman.h file are written and also the fucntions use the variables
// initialized in the hangmna.h file.

//Input: the inputs for this program are all the variables in the hangman.h file.
//Process: there needs to be functions defined in the class function that can
// be written here. The computer also calculates things like which words to 
// be used and what body parts and other things to display. 
//Output: the outputs are things like error messages, prompts, the display like
// the hangman, alphabet, and word being guessed with underscores and letters.


#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cctype>
#include "hangman.h"

using namespace std;

Hangman::Hangman() {
	body[0] = "    ____   ";
	body[1] = "    |  |   ";
	body[2] = "       |   ";
	body[3] = "       |   ";
	body[4] = "       |   ";
	body[5] = "       |   ";
	body[6] = "       |   ";
	body[7] = "       |   ";
	body[8] = "_______|___";

	badGuess = 0;
	wordLength = 0;
	gamesPlayed = 0;
	gamesLost = 0;
	gamesWon = 0;
	numOfWords = 0;
	noMatchedLetters = 0;
	matchingLetters = 0;
	currentWord = 0;

	for (int i = 0; i < 26; i++) {
		alphabet[i] = 65 + i;
		lettersUsed[i] = false;
	}

	for (int j = 0; j < LIMIT; j++) {
		underscoreArray[j] = '_';
	}
}

bool Hangman::initializeFile(string fileName) {
	ifstream inputFile;
	inputFile.open(fileName);

	if (!inputFile.is_open()){
		return false;
	}
	
	while (inputFile >> words[numOfWords]) {
		numOfWords++;
	}
	
	inputFile.close();
	return true;
}

void Hangman::displayStatistics() const {
	cout << "Number of games played: " << gamesPlayed << endl;
	cout << "Number of games lost: " << gamesLost << endl;
	cout << "Number of games won: " << gamesWon << endl;
	cout << "Number of words read from file: " << numOfWords << endl;
}

bool Hangman::newWord() {
	if (gamesPlayed == 0) {
		srand(static_cast<unsigned int>(time(NULL)));
		for (int j = 0; j < numOfWords; j++) {
			int randomShuffle = rand() % numOfWords;
			string temp = words[j];
			words[j] = words[randomShuffle];
			words[randomShuffle] = temp;
		}
	}

	if (gamesPlayed != numOfWords) {
		wordBeingUsed = words[gamesPlayed];
		gamesPlayed++;
		return true;
	}
	else {
		cout << "There are no more words to guess." << endl;
		return false;
	}
}

void Hangman::displayGame() {
	//cout << endl << endl << "################ NEXT TURN ################" << endl;
	for (int display = 0; display <= 8; display++){
		cout << body[display] << endl;
	}
	cout << endl;

	wordLength = wordBeingUsed.length();

	for (int j = 0; j < wordLength; j++) {
		cout << underscoreArray[j] << " ";
	}
	cout << endl << endl;

	for (int i = 0; i < alphabetLimit; i++) {
		if (lettersUsed[i] == false) {
			cout << alphabet[i] << " ";
		}
		else {
			cout << " _ ";
		}
	}
	cout << endl << endl;
}

bool Hangman::guess(char letter, bool& done, bool& won) {
	//toupper(letter);
	if (!isalpha(letter) || lettersUsed[letter - 65] == true) {
		return false;
	}
	cout << "You guessed the letter, " << letter << "." << endl;

	lettersUsed[letter - 65] = true;

	for (int i = 0; i < wordLength; i++) {
		if (wordBeingUsed[i] == letter) {
			underscoreArray[i] = letter;
		}
		else if (wordBeingUsed[i] != letter) {
			noMatchedLetters++;
		}
	}

	if (noMatchedLetters == wordLength) {
		cout << "Your guess was wrong!" << endl;
		noMatchedLetters = 0;
		badGuess++;
	}
	else {
		cout << "Your guess was correct!" << endl;
		noMatchedLetters = 0;
	}

	for (int j = 0; j < wordLength; j++) {
		if (underscoreArray[j] == wordBeingUsed[j]) {
			matchingLetters++;
		}
	}
	if (matchingLetters == wordLength) {
		gamesWon++;
		matchingLetters = 0;
		won = true;
		done = true;
		return true;
	}
	matchingLetters = 0;

	if (badGuess == 1) {
		body[2] = "    O  |   ";
	}
	else if (badGuess == 2) {
		body[3] = "    |  |   ";
	}
	else if (badGuess == 3) {
		body[4] = "   -|  |   ";
	}
	else if (badGuess == 4) {
		body[4] = "   -|- |   ";
	}
	else if (badGuess == 5) {
		body[5] = "    |  |   ";
	}
	else if (badGuess == 6) {
		body[6] = "   /   |   ";
	}
	else if (badGuess == 7) {
		body[6] = "   / \\ |   ";
		done = true;
		cout << "You lost!" << endl;
		gamesLost++;
	}

	return true;
}
void Hangman::revealWord() const {
	cout << "The word is " << wordBeingUsed << endl;
}

void Hangman::reset() {
	body[0] = "    ____   ";
	body[1] = "    |  |   ";
	body[2] = "       |   ";
	body[3] = "       |   ";
	body[4] = "       |   ";
	body[5] = "       |   ";
	body[6] = "       |   ";
	body[7] = "       |   ";
	body[8] = "_______|___";
	
	badGuess = 0;

	for (int i = 0; i < 26; i++) {
		lettersUsed[i] = false;
	}

	for (int j = 0; j < LIMIT; j++) {
		underscoreArray[j] = '_';
	}
}
