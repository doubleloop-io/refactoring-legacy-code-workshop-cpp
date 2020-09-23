#include "QuestionDeck.h"
#include <sstream>
#include <iostream>

static std::string create_question(int index, std::string category)
{
	std::ostringstream oss(std::ostringstream::out);
	oss << category + " Question " << index;
	return oss.str();
}

static bool list_contains(std::list<int>& list, int value)
{
	return  std::find(list.begin(), list.end(), value) != list.end();
}

void QuestionDeck::fill_questions()
{
	for (int i = 0; i < 50; i++)
	{
		popQuestions_.push_back(create_question(i, "Pop"));
		scienceQuestions_.push_back(create_question(i, "Science"));
		sportsQuestions_.push_back(create_question(i, "Sports"));
		rockQuestions_.push_back(create_question(i, "Rock"));
	}
}

std::string QuestionDeck::current_category(int current_player_place)
{
	std::list<int> popPlaces = { 0,4,8 };
	if (list_contains(popPlaces, current_player_place)) return "Pop";

	if (current_player_place == 1) return "Science";
	if (current_player_place == 5) return "Science";
	if (current_player_place == 9) return "Science";

	if (current_player_place == 2) return "Sports";
	if (current_player_place == 6) return "Sports";
	if (current_player_place == 10) return "Sports";

	if (current_player_place == 3) return "Rock";
	if (current_player_place == 7) return "Rock";
	if (current_player_place == 11) return "Rock";

	return "Rock";
}

std::string QuestionDeck::ask_question(std::string current_category)
{
	if (current_category == "Pop") {
		auto question = popQuestions_.front();
		std::cout << question << std::endl;
		popQuestions_.pop_front();
		return question;
	}
	if (current_category == "Science")
	{
		auto question = scienceQuestions_.front();
		std::cout << question << std::endl;
		scienceQuestions_.pop_front();
		return question;
	}
	if (current_category == "Sports")
	{
		auto question = sportsQuestions_.front();
		std::cout << question << std::endl;
		sportsQuestions_.pop_front();
		return question;
	}
	if (current_category == "Rock")
	{
		auto question = rockQuestions_.front();
		std::cout << question << std::endl;
		rockQuestions_.pop_front();
		return question;
	}

	return "";
}
