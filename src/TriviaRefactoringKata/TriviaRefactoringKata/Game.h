#pragma once 

#include <list>
#include <vector>
#include <string>
#include "QuestionDeck.h"

using namespace std;

class Game {

private:
	vector<string> players;

	int places[6];
	int purses[6];

	bool inPenaltyBox[6];

	QuestionDeck deck;

	unsigned int currentPlayer;
	bool isGettingOutOfPenaltyBox;

public:
	Game();
	bool isPlayable();
	bool add(string playerName);

	int howManyPlayers();
	void roll(int roll);

private:
	void askQuestion();
	string currentCategory();

public:
	bool wasCorrectlyAnswered();
	bool wrongAnswer();

private:
	bool didPlayerWin();
};
