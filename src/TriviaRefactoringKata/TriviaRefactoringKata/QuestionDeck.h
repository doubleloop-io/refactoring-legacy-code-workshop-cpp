#pragma once
#include <list>

using namespace std;

class QuestionDeck
{
public:
	list<string> popQuestions_;
	list<string> scienceQuestions_;
	list<string> sportsQuestions_;
	list<string> rockQuestions_;

	string createRockQuestion(int index);
	void fill_question_deck();
	string current_category(int current_place);
	void ask_question(string current_category);
};
