#include "QuestionDeck.h"
#include <sstream>

using namespace std;

QuestionsCategory& QuestionDeck::get_or_add(string category)
{
	auto it = categories_.find(category);
	if (it == categories_.end())
		categories_.insert(pair<string, QuestionsCategory>(category, QuestionsCategory()));

	return categories_.find(category)->second;
}

string QuestionDeck::make_question(string categoryName, int index)
{
	ostringstream oss(ostringstream::out);
	oss << categoryName << " Question " << index;
	return oss.str();
}

void QuestionDeck::fill_question_deck()
{
	get_or_add("Pop").place_on(0);
	get_or_add("Pop").place_on(4);
	get_or_add("Pop").place_on(8);

	get_or_add("Science").place_on(1);
	get_or_add("Science").place_on(5);
	get_or_add("Science").place_on(9);

	get_or_add("Sports").place_on(2);
	get_or_add("Sports").place_on(6);
	get_or_add("Sports").place_on(10);

	get_or_add("Rock").place_on(3);
	get_or_add("Rock").place_on(7);
	get_or_add("Rock").place_on(11);

	for (auto& pair : categories_)
	{
		for (int i = 0; i < 50; i++)
		{
			pair.second.append_question(make_question(pair.first, i));
		}
	}
}

void QuestionDeck::place_category_on(int place, string category)
{
	get_or_add(category).place_on(place);
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

void QuestionDeck::append_question_for(string question, string category)
{
	get_or_add(category).append_question(question);
}

string QuestionDeck::next_question_for(string category)
{
	auto it = categories_.find(category);
	if (it == categories_.end())
		throw InvalidCategoryException(category);

	return it->second.next_question();
}
