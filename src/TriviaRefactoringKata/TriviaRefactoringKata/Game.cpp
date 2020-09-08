#include "Game.h"
#include <iostream>
#include <sstream>

using namespace std;

void Game::fill_question_deck()
{
	setup_category(50, { 0,4,8 }, "Pop");
	setup_category(50, { 1,5,9 }, "Science");
	setup_category(50, { 2,6,10 }, "Sports");
	setup_category(50, { 3,7,11 }, "Rock");
}

Game::Game() : places{}, purses{}, currentPlayer(0){
}

bool Game::isPlayable()
{
	return (howManyPlayers() >= 2);
}

bool Game::add(string playerName) {
	players.push_back(playerName);
	places[howManyPlayers()] = 0;
	purses[howManyPlayers()] = 0;
	inPenaltyBox[howManyPlayers()] = false;

	cout << playerName << " was added" << endl;
	cout << "They are player number " << players.size() << endl;
	return true;
}

int Game::howManyPlayers()
{
	return (int)players.size();
}

void Game::roll(int roll)
{
	cout << players[currentPlayer] << " is the current player" << endl;
	cout << "They have rolled a " << roll << endl;

	if (inPenaltyBox[currentPlayer])
	{
		if (roll % 2 != 0)
		{
			isGettingOutOfPenaltyBox = true;

			cout << players[currentPlayer] << " is getting out of the penalty box" << endl;
			places[currentPlayer] = places[currentPlayer] + roll;
			if (places[currentPlayer] > 11) places[currentPlayer] = places[currentPlayer] - 12;

			cout << players[currentPlayer] << "'s new location is " << places[currentPlayer] << endl;
			cout << "The category is " << currentCategory() << endl;
			askQuestion();
		}
		else
		{
			cout << players[currentPlayer] << " is not getting out of the penalty box" << endl;
			isGettingOutOfPenaltyBox = false;
		}

	}
	else
	{

		places[currentPlayer] = places[currentPlayer] + roll;
		if (places[currentPlayer] > 11) places[currentPlayer] = places[currentPlayer] - 12;

		cout << players[currentPlayer] << "'s new location is " << places[currentPlayer] << endl;
		cout << "The category is " << currentCategory() << endl;
		askQuestion();
	}
}

void Game::askQuestion()
{
	auto current_category = currentCategory();
	auto question = deck.next_question_for(current_category);
	cout << question << endl;
}

string Game::currentCategory()
{
	auto current_place = places[currentPlayer];
	return deck.category_on(current_place);
}

void Game::fill_questions_for(int count, string category)
{
	for (int i = 0; i < count; i++)
		deck.append_question_for(make_question(category, i), category);
}

string Game::make_question(string category, int index)
{
	ostringstream oss(ostringstream::out);
	oss << category << " Question " << index;
	return oss.str();
}

void Game::setup_category(int questionsCount, list<int> places, string category)
{
	for (auto item : places)
		deck.place_category_on(item, category);

	for (int i = 0; i < questionsCount; i++)
		deck.append_question_for(make_question(category, i), category);
}

bool Game::wasCorrectlyAnswered()
{
	if (inPenaltyBox[currentPlayer])
	{
		if (isGettingOutOfPenaltyBox)
		{
			cout << "Answer was correct!!!!" << endl;
			purses[currentPlayer]++;
			cout << players[currentPlayer]
				<< " now has "
				<< purses[currentPlayer]
				<< " Gold Coins." << endl;

			bool winner = didPlayerWin();
			currentPlayer++;
			if (currentPlayer == players.size()) currentPlayer = 0;

			return winner;
		}
		else
		{
			currentPlayer++;
			if (currentPlayer == players.size()) currentPlayer = 0;
			return true;
		}



	}
	else
	{

		cout << "Answer was corrent!!!!" << endl;
		purses[currentPlayer]++;
		cout << players[currentPlayer]
			<< " now has "
			<< purses[currentPlayer]
			<< " Gold Coins." << endl;

		bool winner = didPlayerWin();
		currentPlayer++;
		if (currentPlayer == players.size()) currentPlayer = 0;

		return winner;
	}
}

bool Game::wrongAnswer()
{
	cout << "Question was incorrectly answered" << endl;
	cout << players[currentPlayer] + " was sent to the penalty box" << endl;
	inPenaltyBox[currentPlayer] = true;

	currentPlayer++;
	if (currentPlayer == players.size()) currentPlayer = 0;
	return true;
}


bool Game::didPlayerWin()
{
	return !(purses[currentPlayer] == 6);
}