﻿#include "QuestionDeck.h"
#include <sstream>
#include <iostream>

using namespace std;

string QuestionDeck::createRockQuestion(int index)
{
	char indexStr[127];
	sprintf_s(indexStr, "Rock Question %d", index);
	return indexStr;
}

void QuestionDeck::fill_question_deck()
{
	for (int i = 0; i < 50; i++)
	{
		ostringstream oss(ostringstream::out);
		oss << "Pop Question " << i;
		popQuestions_.push_back(oss.str());

		char str[255];
		sprintf_s(str, "Science Question %d", i);
		scienceQuestions_.push_back(str);

		char str1[255];
		sprintf_s(str1, "Sports Question %d", i);
		sportsQuestions_.push_back(str1);

		rockQuestions_.push_back(createRockQuestion(i));
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
	if (current_category == "Pop")
	{
		auto question = popQuestions_.front();
		cout << question << endl;
		popQuestions_.pop_front();
	}
	if (current_category == "Science")
	{
		auto question = scienceQuestions_.front();
		cout << question << endl;
		scienceQuestions_.pop_front();
	}
	if (current_category == "Sports")
	{
		auto question = sportsQuestions_.front();
		cout << question << endl;
		sportsQuestions_.pop_front();
	}
	if (current_category == "Rock")
	{
		auto question = rockQuestions_.front();
		cout << question << endl;
		rockQuestions_.pop_front();
	}
	return "";
}
