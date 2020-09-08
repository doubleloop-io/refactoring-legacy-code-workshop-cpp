#pragma once
#include <string>
#include "QuestionsCategory.h"

using namespace std;

class QuestionDeck
{
public:
	QuestionDeck();
	void fill_question_deck();
	string category_on(int place);
	string ask_question(string category);

private:
	QuestionsCategory pop_;
	QuestionsCategory science_;
	QuestionsCategory sports_;
	QuestionsCategory rock_;

	string make_question(string categoryName, int index);
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
