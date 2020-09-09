#include "Game.h"
#include <ctime>
#include "GameRunner.h"

bool GameRunner::notAWinner = false;

void GameRunner::run(int argc, char* argv[])
{
	srand((int)time(NULL));

	Game aGame;

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
