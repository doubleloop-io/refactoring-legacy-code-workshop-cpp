#include <algorithm>
#include "QuestionsCategory.h"

void QuestionsCategory::append_question(std::string question)
{
	questions_.push_back(question);
}

bool QuestionsCategory::is_placed_on(int place)
{
	return std::find(places_.begin(), places_.end(), place) != places_.end();
}

void QuestionsCategory::place_on(int place)
{
	places_.push_back(place);
}

std::string QuestionsCategory::next_question()
{
	if (questions_.empty()) throw EndOfQuestionsException();

	std::string question = questions_.front();
	questions_.pop_front();
	return question;
}
