#include "GameRunner.h"
#include <cstdlib>
#include <ctime>
#include <sstream>

bool GameRunner::notAWinner;

void GameRunner::run(int seed)
{
	srand(seed);

	Game aGame;

	setup_category(50, { 0,4,8 }, "Pop", aGame);
	setup_category(50, { 1,5,9 }, "Science", aGame);
	setup_category(50, { 2,6,10 }, "Sports", aGame);
	setup_category(50, { 3,7,11 }, "Rock", aGame);

	aGame.add("Chet");
	aGame.add("Pat");
	aGame.add("Sue");

	do
	{

		aGame.roll(rand() % 5 + 1);

		if (rand() % 9 == 7)
		{
			notAWinner = aGame.wrongAnswer();
		}
		else
		{
			notAWinner = aGame.wasCorrectlyAnswered();
		}
	} while (notAWinner);
}

void GameRunner::setup_category(int questionsCount, std::list<int> places, std::string category, Game& game)
{
	game.setup_category(make_questions(category, questionsCount), places, category);
}

string GameRunner::make_question(string category, int index)
{
	ostringstream oss(ostringstream::out);
	oss << category << " Question " << index;
	return oss.str();
}

list<string> GameRunner::make_questions(string category, int count)
{
	list<string> questions;
	for (int i = 0; i < count; i++)
		questions.push_back(make_question(category, i));
	return questions;
}

void GameRunner::run(int argc, char* argv[])
{
	run((int)time(NULL));
}

