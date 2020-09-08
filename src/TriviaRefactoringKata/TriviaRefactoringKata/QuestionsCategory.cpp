#include <algorithm>
#include "QuestionsCategory.h"

QuestionsCategory::QuestionsCategory(std::string name)
	:name_(name)
{
}

QuestionsCategory::QuestionsCategory(std::string name, std::list<int> places)
	:name_(name), places_(places)
{
}

void QuestionsCategory::append_question(std::string question)
{
	questions_.push_back(question);
}

bool QuestionsCategory::is_placed_on(int place)
{
	return std::find(places_.begin(), places_.end(), place) != places_.end();
}

std::string QuestionsCategory::name()
{
	return name_;
}

void QuestionsCategory::place_on(int place)
{
	places_.push_back(place);
}

std::string QuestionsCategory::next_question()
{
	if (questions_.empty()) throw EndOfQuestionsException(name_);

	std::string question = questions_.front();
	questions_.pop_front();
	return question;
}
