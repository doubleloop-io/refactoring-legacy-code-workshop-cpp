#pragma once
#include <list>

class QuestionsCategory
{
public:
	QuestionsCategory(std::string name, std::list<int> places);
	void append_question(std::string question);
	bool is_place_on(int place);
	std::string name();
	std::string next_question();

private:
	std::string name_;
	std::list<int> places_;
};
