#pragma once

class GameRunner
{
public:
	void init_rand();
	void run(int argc, char *argv[]);

private:
	bool notAWinner = false;
};
