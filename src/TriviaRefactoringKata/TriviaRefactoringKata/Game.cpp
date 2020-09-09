#include "Game.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>

using namespace std;

Game::Game() : places{}, purses{}, currentPlayer(0){
	deck.fill_questions();
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
	if (currentCategory() == "Pop")
	{
		cout << deck.popQuestions_.front() << endl;
		deck.popQuestions_.pop_front();
	}
	if (currentCategory() == "Science")
	{
		cout << deck.scienceQuestions_.front() << endl;
		deck.scienceQuestions_.pop_front();
	}
	if (currentCategory() == "Sports")
	{
		cout << deck.sportsQuestions_.front() << endl;
		deck.sportsQuestions_.pop_front();
	}
	if (currentCategory() == "Rock")
	{
		cout << deck.rockQuestions_.front() << endl;
		deck.rockQuestions_.pop_front();
	}
}

string Game::currentCategory()
{
	auto current_player_place = places[currentPlayer];
	return deck.current_category(current_player_place);
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