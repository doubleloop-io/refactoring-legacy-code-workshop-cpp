#include "QuestionCategory.h"

QuestionCategory::QuestionCategory(std::string name, const std::unordered_set<int> places)
	: name_(name), places_(places)
{
}

void QuestionCategory::append_question(const std::string question)
{
	questions_.push_back(question);
}

std::string QuestionCategory::name() const
{
	return name_;
}

bool QuestionCategory::places_contains(int place) const
{
	return places_.find(place) != places_.end();
}

std::string QuestionCategory::next_question()
{
	auto question = questions_.front();
	questions_.pop_front();
	return question;
}
