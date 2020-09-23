#include "QuestionDeck.h"
#include <sstream>
#include <iostream>
#include <unordered_set>

static std::string create_question(int index, std::string category)
{
	std::ostringstream oss(std::ostringstream::out);
	oss << category + " Question " << index;
	return oss.str();
}

static bool places_contains(std::unordered_set<int>& places, int value)
{
	return places.find(value) != places.end();
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

std::string QuestionDeck::find_category_for(int place)
{
	if (places_contains(popPlaces_, place)) return "Pop";
	if (places_contains(sciencePlaces_, place)) return "Science";
	if (places_contains(sportsPlaces_, place)) return "Sports";
	if (places_contains(rockPlaces_, place)) return "Rock";
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
