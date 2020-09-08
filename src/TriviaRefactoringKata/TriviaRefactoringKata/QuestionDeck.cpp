﻿#include "QuestionDeck.h"
#include <sstream>
#include <algorithm>

using namespace std;

string QuestionDeck::make_question(string categoryName, int index)
{
	ostringstream oss(ostringstream::out);
	oss << categoryName << " Question " << index;
	return oss.str();
}

bool QuestionDeck::list_contains(int value, list<int> list)
{
	return std::find(list.begin(), list.end(), value) != list.end();
}

string QuestionDeck::next_question(list<string>& questions)
{
	string question = questions.front();
	questions.pop_front();
	return question;
}

QuestionDeck::QuestionDeck()
	: popPlaces_{ 0, 4, 8 },
	sciencePlaces_{ 1, 5, 9 },
	sportsPlaces_{ 2, 6, 10 },
	rockPlaces_{ 3, 7, 11 }
{
}

void QuestionDeck::fill_question_deck()
{
	for (int i = 0; i < 50; i++)
	{
		popQuestions_.push_back(make_question("Pop", i));
		scienceQuestions_.push_back(make_question("Science", i));
		sportsQuestions_.push_back(make_question("Sports", i));
		rockQuestions_.push_back(make_question("Rock", i));
	}
}

string QuestionDeck::category_on(int place)
{
	if (list_contains(place, popPlaces_)) return "Pop";
	if (list_contains(place, sciencePlaces_)) return "Science";
	if (list_contains(place, sportsPlaces_)) return "Sports";
	if (list_contains(place, rockPlaces_)) return "Rock";

	throw InvalidPlaceException(place);
}

string QuestionDeck::ask_question(string current_category)
{
	string question = "";
	if (current_category == "Pop")
		question = next_question(popQuestions_);
	if (current_category == "Science")
		question = next_question(scienceQuestions_);
	if (current_category == "Sports")
		question = next_question(sportsQuestions_);
	if (current_category == "Rock")
		question = next_question(rockQuestions_);
	return question;
}
