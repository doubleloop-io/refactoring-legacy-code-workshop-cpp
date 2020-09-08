#pragma once
#include <list>
#include "Game.h"

class GameRunner
{
public:
	static void run(int argc, char *argv[]);
	static void run(int seed);

private:
	static bool notAWinner;
	static void setup_category(int questionsCount, std::list<int> places, std::string category, Game& game);
	static string make_question(string category, int index);
	static list<string> make_questions(string category, int count);
};
