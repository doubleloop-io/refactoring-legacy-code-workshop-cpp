#include "QuestionDeck.h"
#include <sstream>
#include <iostream>

static std::string create_rock_question(int index)
{
	char indexStr[127];
	sprintf_s(indexStr, "Rock Question %d", index);
	return indexStr;
}

void QuestionDeck::fill_questions()
{
	for (int i = 0; i < 50; i++)
	{
		std::ostringstream oss(std::ostringstream::out);
		oss << "Pop Question " << i;

		popQuestions_.push_back(oss.str());

		char str[255];
		sprintf_s(str, "Science Question %d", i);
		scienceQuestions_.push_back(str);

		char str1[255];
		sprintf_s(str1, "Sports Question %d", i);
		sportsQuestions_.push_back(str1);

		rockQuestions_.push_back(create_rock_question(i));
	}
}

std::string QuestionDeck::current_category(int current_player_place)
{
	if (current_player_place == 0) return "Pop";
	if (current_player_place == 4) return "Pop";
	if (current_player_place == 8) return "Pop";
	if (current_player_place == 1) return "Science";
	if (current_player_place == 5) return "Science";
	if (current_player_place == 9) return "Science";
	if (current_player_place == 2) return "Sports";
	if (current_player_place == 6) return "Sports";
	if (current_player_place == 10) return "Sports";
	return "Rock";
}

void QuestionDeck::ask_question(std::string current_category)
{
	if (current_category == "Pop") {
		std::cout << popQuestions_.front() << std::endl;
		popQuestions_.pop_front();
	}
	if (current_category == "Science")
	{
		std::cout << scienceQuestions_.front() << std::endl;
		scienceQuestions_.pop_front();
	}
	if (current_category == "Sports")
	{
		std::cout << sportsQuestions_.front() << std::endl;
		sportsQuestions_.pop_front();
	}
	if (current_category == "Rock")
	{
		std::cout << rockQuestions_.front() << std::endl;
		rockQuestions_.pop_front();
	}
}
