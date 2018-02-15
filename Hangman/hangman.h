#include <iostream>
#pragma once

class Hangman {
private:
	int gamesPlayed, gamesWon, gamesLost, badGuess, wordLength, currentWord;
	int numOfWords, noMatchedLetters, matchingLetters;
	std::string presentWord;
	static const int numOfLines = 9;
	std::string body[numOfLines];
	static const int LIMIT = 100;
	std::string words[LIMIT];
	static const int alphabetLimit = 26;
	char alphabet[alphabetLimit];
	bool lettersUsed[alphabetLimit];
	std::string wordBeingUsed;
	static const int underscoreArrayLimit = 100;
	char underscoreArray[underscoreArrayLimit];
public:
	Hangman();
	//This is the constructor of the hangman class.
	//pre(conditions): there needs to be several variable initialized for this
	// function to work properly.
	//post(conditions): there are no changes that affect this class.
	bool initializeFile(std::string fileName);
	//This is the function that takes the file containing the words to be
	// guessed in the game.
	//pre(conditions): There needs to be a file inputed by the user for this
	// function to work correctly.
	//post(conditions): There are no changes that affect this fucntion.
	void displayStatistics() const;
	//This is the function that displays the user's statistics.
	//pre(conditions): there needs to be numbers in the variables used in this
	// function for the function to do its job.
	//post(condition): there are no changes that affect this function.
	bool newWord();
	//This function gets a new word for the user when he is done with the game.
	//pre(conditions): there needs to be variables initialized for this function
	// to work.
	//post(condition): The changes that affect the class members are if the player
	// decides to only play one game and then the new word function only works once.
	void displayGame();
	//This function displays the game itself, like the hangman, alphabet, and 
	// word being guessed in the form of underscores or correct guessed letters.
	//pre(condition): The pre conditions are that there needs to be variables that
	// are changing to change the display itself.
	//post(condition): there could be things in other functions that change the
	// display of the game.
	bool guess(char letter, bool& done, bool& won);
	//This is the function that runs the guessing part of the game.
	//pre(condition): there are things like variables that need to be present
	// and have variables. There are also the parameters that need to be a letter
	// and need to be false.
	//post(condition): there are things that change like variables that affect the 
	// function. There are also things like the bools for winning and being done
	// that determine the functions uses.
	void revealWord() const;
	//This function reveals the word being guessed.
	//pre(condition): there needs to be a word to reveal.
	//post(condition): The change for this function is the word that changes with
	// the game.
	void reset();
	//This function resets some variables that need to be reset every game.
	//pre(condition): There are no conditions that need to be true except there
	// needs to be variables to reset like the body.
	//post(condition): There is nothing that affects what this function does.
};
