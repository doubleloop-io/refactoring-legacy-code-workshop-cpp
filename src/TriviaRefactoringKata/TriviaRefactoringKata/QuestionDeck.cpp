#include "QuestionDeck.h"

using namespace std;

QuestionsCategory& QuestionDeck::get_or_add(string category)
{
	auto it = categories_.find(category);
	if (it == categories_.end())
		categories_.insert(pair<string, QuestionsCategory>(category, QuestionsCategory()));

	return categories_.find(category)->second;
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
