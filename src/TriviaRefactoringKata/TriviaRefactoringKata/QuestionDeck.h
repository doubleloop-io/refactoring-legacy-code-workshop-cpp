#pragma once
#include <list>

class QuestionDeck
{
public:
	std::list<std::string> popQuestions_;
	std::list<std::string> scienceQuestions_;
	std::list<std::string> sportsQuestions_;
	std::list<std::string> rockQuestions_;

	std::string createRockQuestion(int index);
};
