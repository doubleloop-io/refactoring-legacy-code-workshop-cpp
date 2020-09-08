#include "QuestionsCategory.h"

QuestionsCategory::QuestionsCategory(std::string name, std::list<int> places)
	:name_(name), places_(places)
{
}

void QuestionsCategory::append_question(std::string question)
{
}

bool QuestionsCategory::is_place_on(int place)
{
	return false;
}

std::string QuestionsCategory::name()
{
	return  "";
}

std::string QuestionsCategory::next_question()
{
	return  "";
}
