#pragma once
#include <string>
#include <map>
#include "QuestionsCategory.h"

using namespace std;

class QuestionDeck
{
public:
	void fill_question_deck();

	void place_category_on(int place, string category);
	string category_on(int place);

	void append_question_for(string question, string category);
	string next_question_for(string category);

private:
	map<string, QuestionsCategory> categories_;

	QuestionsCategory& get_or_add(string category);

	string make_question(string category, int index);
	void fill_questions_for(int count, string category);
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

class InvalidCategoryException : public exception
{
public:
	InvalidCategoryException(string category)
		:msg_("Invalid category: " + category)
	{ }

private:
	string msg_;

	const char * what() const throw ()
	{
		return msg_.c_str();
	}
};
