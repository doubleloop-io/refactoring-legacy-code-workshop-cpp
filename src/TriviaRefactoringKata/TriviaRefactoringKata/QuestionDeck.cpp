#include "QuestionDeck.h"
#include <sstream>
#include <iostream>

using namespace std;

string QuestionDeck::createRockQuestion(int index)
{
	char indexStr[127];
	sprintf_s(indexStr, "Rock Question %d", index);
	return indexStr;
}

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
	if (current_place == 0) return "Pop";
	if (current_place == 4) return "Pop";
	if (current_place == 8) return "Pop";
	if (current_place == 1) return "Science";
	if (current_place == 5) return "Science";
	if (current_place == 9) return "Science";
	if (current_place == 2) return "Sports";
	if (current_place == 6) return "Sports";
	if (current_place == 10) return "Sports";
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
