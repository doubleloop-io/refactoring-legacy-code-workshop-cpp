#include "QuestionDeck.h"
#include <sstream>
#include <algorithm>

using namespace std;

string QuestionDeck::make_question(string categoryName, int index)
{
	ostringstream oss(ostringstream::out);
	oss << categoryName << " Question " << index;
	return  oss.str();
}

bool QuestionDeck::list_contains(int value, list<int> list)
{
	return std::find(list.begin(), list.end(), value) != list.end();
}

QuestionDeck::QuestionDeck()
	: popPlaces_{ 0,4,8 },
	sciencePlaces_{ 1,5,9 },
	sportsPlaces_{ 2,6,10 },
	rockPlaces_{ 3,7,11 }
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

string QuestionDeck::current_category(int current_place)
{
	if (list_contains(current_place, popPlaces_)) return "Pop";
	if (list_contains(current_place, sciencePlaces_)) return "Science";
	if (list_contains(current_place, sportsPlaces_)) return "Sports";
	if (list_contains(current_place, rockPlaces_)) return "Rock";

	return "Rock";
}

string QuestionDeck::ask_question(string current_category)
{
	string question = "";
	if (current_category == "Pop")
	{
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
	return question;
}
