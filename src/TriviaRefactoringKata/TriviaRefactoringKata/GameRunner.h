#pragma once

class GameRunner
{
public:
	static void run(int argc, char *argv[]);
	static void run(int seed);

private:
	static bool notAWinner;
};
