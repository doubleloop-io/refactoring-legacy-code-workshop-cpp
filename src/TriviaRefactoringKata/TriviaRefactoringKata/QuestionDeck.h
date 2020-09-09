﻿#pragma once
#include <list>

class QuestionDeck
{
public:
	std::list<std::string> popQuestions_;
	std::list<std::string> scienceQuestions_;
	std::list<std::string> sportsQuestions_;
	std::list<std::string> rockQuestions_;

	std::string createRockQuestion(int index);
	void fill_questions();
	std::string current_category(int current_player_place);
	void ask_question(std::string current_category);
};
