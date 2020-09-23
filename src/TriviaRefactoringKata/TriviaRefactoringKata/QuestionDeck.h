#pragma once
#include <list>

class QuestionDeck
{
public:
	void fill_questions();
	std::string current_category(int current_player_place);
	std::string ask_question(std::string current_category);

private:
	std::list<std::string> popQuestions_;
	std::list<std::string> scienceQuestions_;
	std::list<std::string> sportsQuestions_;
	std::list<std::string> rockQuestions_;
};
