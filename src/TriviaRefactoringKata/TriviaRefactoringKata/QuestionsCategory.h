#pragma once
#include <list>
#include <string>

class QuestionsCategory
{
public:
	QuestionsCategory(std::string name, std::list<int> places);
	void append_question(std::string question);
	bool is_placed_on(int place);
	std::string name();
	std::string next_question();

private:
	std::string name_;
	std::list<int> places_;
	std::list<std::string> questions_;
};

class EndOfQuestionsException : public std::exception
{
public:
	EndOfQuestionsException(std::string category)
		:msg_("Invalid place: " + category)
	{ }

private:
	std::string msg_;

	const char * what() const throw ()
	{
		return msg_.c_str();
	}
};
