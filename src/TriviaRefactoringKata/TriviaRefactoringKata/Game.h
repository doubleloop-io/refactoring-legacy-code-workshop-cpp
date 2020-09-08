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
	bool isPlayable();
	bool add(string playerName);
	void setup_category(list<string> questions, list<int> places, string category);
	static string make_question(string category, int index);
	static list<string> make_questions(string category, int count);

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
