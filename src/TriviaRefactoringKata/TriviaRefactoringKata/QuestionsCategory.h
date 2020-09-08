#pragma once
#include <list>
#include <string>

class QuestionsCategory
{
public:
	void place_on(int place);
	bool is_placed_on(int place);

	void append_question(std::string question);
	std::string next_question();

private:
	std::string name_;
	std::list<int> places_;
	std::list<std::string> questions_;
};

class EndOfQuestionsException : public std::exception
{
public:
	EndOfQuestionsException()
		:msg_("End of questions for requested category")
	{ }

private:
	std::string msg_;

	const char * what() const throw ()
	{
		return msg_.c_str();
	}
};
