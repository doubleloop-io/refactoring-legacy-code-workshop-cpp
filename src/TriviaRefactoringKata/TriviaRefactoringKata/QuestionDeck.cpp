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
	std::list<int> popPlaces = {0,4,8};
	bool popFound = std::find(popPlaces.begin(), popPlaces.end(), current_place) != popPlaces.end();
	if (popFound) return "Pop";

	if (current_place == 1 ||
		current_place == 5 ||
		current_place == 9) return "Science";

	if (current_place == 2 ||
		current_place == 6 ||
		current_place == 10) return "Sports";

	if (current_place == 3 ||
		current_place == 7 ||
		current_place == 11) return "Rock";

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
