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

static bool places_contains(const std::unordered_set<int>& places, int value)
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

std::string QuestionDeck::find_category_for(int place) const
{
	if (places_contains(popPlaces_, place)) return "Pop";
	if (places_contains(sciencePlaces_, place)) return "Science";
	if (places_contains(sportsPlaces_, place)) return "Sports";
	if (places_contains(rockPlaces_, place)) return "Rock";
	return "Rock";
}

std::string QuestionDeck::ask_question(std::string current_category)
{
	std::string question = "";
	if (current_category == "Pop") {
		question = popQuestions_.front();
		popQuestions_.pop_front();
	}
	if (current_category == "Science")
	{
		question = scienceQuestions_.front();
		scienceQuestions_.pop_front();
	}
	if (current_category == "Sports")
	{
		question = sportsQuestions_.front();
		sportsQuestions_.pop_front();
	}
	if (current_category == "Rock")
	{
		question = rockQuestions_.front();
		rockQuestions_.pop_front();
	}

	if (!question.empty())
		std::cout << question << std::endl;

	return question;
}
