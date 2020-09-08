#include <algorithm>
#include "QuestionsCategory.h"

QuestionsCategory::QuestionsCategory(std::string name, std::list<int> places)
	:name_(name), places_(places)
{
}

void QuestionsCategory::append_question(std::string question)
{
	questions_.push_back(question);
}

bool QuestionsCategory::is_place_on(int place)
{
	return std::find(places_.begin(), places_.end(), place) != places_.end();
}

std::string QuestionsCategory::name()
{
	return name_;
}

std::string QuestionsCategory::next_question()
{
	std::string question = questions_.front();
	questions_.pop_front();
	return question;
}
