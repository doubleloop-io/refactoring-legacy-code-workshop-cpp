#include "GameRunner.h"
#include <cstdlib>
#include <ctime>
#include "Game.h"

bool GameRunner::notAWinner;

void GameRunner::run(int seed)
{
	srand(seed);

	Game aGame;

	aGame.setup_category(50, { 0,4,8 }, "Pop");
	aGame.setup_category(50, { 1,5,9 }, "Science");
	aGame.setup_category(50, { 2,6,10 }, "Sports");
	aGame.setup_category(50, { 3,7,11 }, "Rock");

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

void GameRunner::run(int argc, char* argv[])
{
	run((int)time(NULL));
}

