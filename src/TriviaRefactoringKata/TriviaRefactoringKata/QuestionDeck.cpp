﻿#include "QuestionDeck.h"
#include <sstream>

using namespace std;

string QuestionDeck::make_question(string categoryName, int index)
{
	ostringstream oss(ostringstream::out);
	oss << categoryName << " Question " << index;
	return oss.str();
}

QuestionDeck::QuestionDeck()
{
}

void QuestionDeck::fill_question_deck()
{
	categories_.insert(pair<string, QuestionsCategory&>("Pop", pop_));
	categories_.insert(pair<string, QuestionsCategory&>("Science", science_));
	categories_.insert(pair<string, QuestionsCategory&>("Sports", sports_));
	categories_.insert(pair<string, QuestionsCategory&>("Rock", rock_));

	pop_.place_on(0);
	pop_.place_on(4);
	pop_.place_on(8);
	science_.place_on(1);
	science_.place_on(5);
	science_.place_on(9);
	sports_.place_on(2);
	sports_.place_on(6);
	sports_.place_on(10);
	rock_.place_on(3);
	rock_.place_on(7);
	rock_.place_on(11);

	for (auto& pair : categories_)
	{
		for (int i = 0; i < 50; i++)
		{
			pair.second.append_question(make_question(pair.first, i));
		}
	}
}

string QuestionDeck::category_on(int place)
{
	for (auto& pair : categories_)
	{
		if (pair.second.is_placed_on(place))
			return pair.first;
	}

	throw InvalidPlaceException(place);
}

string QuestionDeck::ask_question(string category)
{
	auto it = categories_.find(category);
	if (it == categories_.end())
		throw InvalidCategoryException(category);

	return it->second.next_question();
}
