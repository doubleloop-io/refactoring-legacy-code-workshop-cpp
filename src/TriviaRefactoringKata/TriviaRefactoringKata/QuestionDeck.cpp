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

string QuestionDeck::make_question(string category, int index)
{
	ostringstream oss(ostringstream::out);
	oss << category << " Question " << index;
	return oss.str();
}

void QuestionDeck::fill_questions_for(int count, string category)
{
	for (int i = 0; i < count; i++)
		append_question_for(make_question(category, i), category);
}

void QuestionDeck::fill_question_deck()
{
	place_category_on(0, "Pop");
	place_category_on(4, "Pop");
	place_category_on(8, "Pop");
	fill_questions_for(50, "Pop");

	place_category_on(1, "Science");
	place_category_on(5, "Science");
	place_category_on(9, "Science");
	fill_questions_for(50, "Science");

	place_category_on(2, "Sports");
	place_category_on(6, "Sports");
	place_category_on(10, "Sports");
	fill_questions_for(50, "Sports");

	place_category_on(3, "Rock");
	place_category_on(7, "Rock");
	place_category_on(11, "Rock");
	fill_questions_for(50, "Rock");
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
