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
	void fill_question_deck();
	bool isPlayable();
	bool add(string playerName);

	int howManyPlayers();
	void roll(int roll);

private:
	void askQuestion();
	string currentCategory();
	void fill_questions_for(int count, string category);

public:
	bool wasCorrectlyAnswered();
	bool wrongAnswer();

private:
	bool didPlayerWin();
};
