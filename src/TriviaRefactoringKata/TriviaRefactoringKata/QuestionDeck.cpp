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

static std::string next_question(std::list<std::string>& questions)
{
	auto question = questions.front();
	questions.pop_front();
	return question;
}

void QuestionDeck::fill_questions()
{
	for (int i = 0; i < 50; i++)
	{
		pop_.append_question(create_question(i, pop_.name()));

		scienceQuestions_.push_back(create_question(i, "Science"));
		sportsQuestions_.push_back(create_question(i, "Sports"));
		rockQuestions_.push_back(create_question(i, "Rock"));
	}
}

std::string QuestionDeck::find_category_for(int place) const
{
	if (pop_.places_contains(place)) return pop_.name();

	if (places_contains(sciencePlaces_, place)) return "Science";
	if (places_contains(sportsPlaces_, place)) return "Sports";
	if (places_contains(rockPlaces_, place)) return "Rock";

	throw PlaceNotFoundException(place);
}

std::string QuestionDeck::fetch_next_question(std::string category)
{
	if (category == pop_.name()) return pop_.next_question();

	if (category == "Science") return next_question(scienceQuestions_);
	if (category == "Sports") return next_question(sportsQuestions_);
	if (category == "Rock") return next_question(rockQuestions_);

	return "";
}
