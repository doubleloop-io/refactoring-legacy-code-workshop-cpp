#include "QuestionDeck.h"
#include <sstream>

using namespace std;

string QuestionDeck::make_question(string categoryName, int index)
{
	ostringstream oss(ostringstream::out);
	oss << categoryName << " Question " << index;
	return oss.str();
}

void QuestionDeck::fill_question_deck()
{
	categories_.insert(pair<string, QuestionsCategory>("Pop", QuestionsCategory()));
	categories_.insert(pair<string, QuestionsCategory>("Science", QuestionsCategory()));
	categories_.insert(pair<string, QuestionsCategory>("Sports", QuestionsCategory()));
	categories_.insert(pair<string, QuestionsCategory>("Rock", QuestionsCategory()));

	categories_.at("Pop").place_on(0);
	categories_.at("Pop").place_on(4);
	categories_.at("Pop").place_on(8);

	categories_.at("Science").place_on(1);
	categories_.at("Science").place_on(5);
	categories_.at("Science").place_on(9);

	categories_.at("Sports").place_on(2);
	categories_.at("Sports").place_on(6);
	categories_.at("Sports").place_on(10);

	categories_.at("Rock").place_on(3);
	categories_.at("Rock").place_on(7);
	categories_.at("Rock").place_on(11);

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
	auto it = categories_.find(category);
	if (it == categories_.end())
		categories_.insert(pair<string, QuestionsCategory>(category, QuestionsCategory()));

	categories_.find(category)->second.place_on(place);
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
