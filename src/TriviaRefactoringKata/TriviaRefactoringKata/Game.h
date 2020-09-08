#pragma once 

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

	unsigned int currentPlayer;
	bool isGettingOutOfPenaltyBox;

	QuestionDeck deck;

public:
	Game();
	string createRockQuestion(int index);
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
