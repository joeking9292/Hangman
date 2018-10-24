# Hangman
# Hangman

The game of Hangman is a popular game which consists of guessing a word or phrase by choosing letters and finding out if the letter is contained in the word or phrase and where it is located (i.e. "Wheel of Fortune").

In C++, create a hangman game class. Include the following public member functions:

constructor - initializes all variables and sets up the display array
bool initializeFile(string filename) - reads words from file and stores into array for game, returns false if there is a file problem
void displayStatistics() - displays wins/losses/number of words read from file/number of words still available for play
bool newWord() - randomly chooses new word from list of words, returns false if no more words available
void displayGame() - displays the hangman body, word (with underscores as needed), letters still available
bool guess(char letter, bool& done, bool& won) - processes the user's guess, returns false if letter chosen was not available, done will return true when user is out of guesses, won will return true when user has correctly guessed the word
void revealWord() - displays the word with all letters
The game will work as follows:

The user will see a short description of the game and be allowed to play or not. Once the user chooses to play he/she must provide the name of a file containing a list of words. There will be no more than 100 words and they are all in UPPERCASE letters. A word is chosen randomly from this list for each game until all words have been used or the player chooses to quit.
When the game begins an empty noose is displayed with a series of separated underscore characters that indicate the number of letters in the word to be guessed and a list of the available letters of the alphabet.
As the user guesses a letter, the display updates the result by either putting a single "body part" on the hangman's noose (head, neck, arm, etc.) OR replaces an underscore with the properly guessed letter AND removes the used letter from the available list. This continues until the user runs out of body parts or completes the word.
Repeat as long as the user wishes to play or until the words run out, keeping track of the number of wins and losses.
Notes:

If a letter appears more than once in the word, it will replace more than one underscore.
For testing, use my provided file of words available here:
/home/fac/lundeenk/submit/18wq1430/files/p1input.dat

Body pieces should appear in the following order: head, neck, one arm, other arm, torso, one leg, other leg. 
Hints: p1-hints.txtPreview the document
Your files must be named "hangman.h", "hangman.cpp", and "p1.cpp".
