﻿#pragma once
#include <list>
#include <string>

using namespace std;

class QuestionDeck
{
public:
	QuestionDeck();
	void fill_question_deck();
	string category_on(int place);
	string ask_question(string current_category);

private:
	list<string> popQuestions_;
	list<int> popPlaces_;

	list<string> scienceQuestions_;
	list<int> sciencePlaces_;

	list<string> sportsQuestions_;
	list<int> sportsPlaces_;

	list<string> rockQuestions_;
	list<int> rockPlaces_;

	string make_question(string categoryName, int index);
	bool list_contains(int value, list<int> list);
	string next_question(list<string>& questions);
};

class InvalidPlaceException : public exception
{
public:
	InvalidPlaceException(int place)
		:msg_("Invalid place: " + to_string(place))
	{ }

private:
	string msg_;

	const char * what() const throw ()
	{
		return msg_.c_str();
	}
};
