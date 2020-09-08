#pragma once
#include <list>

using namespace std;

class QuestionDeck
{
public:
	void fill_question_deck();
	string current_category(int current_place);
	string ask_question(string current_category);

private:
	list<string> popQuestions_;
	list<string> scienceQuestions_;
	list<string> sportsQuestions_;
	list<string> rockQuestions_;

	string make_question(string categoryName, int index);
	bool list_contains(int value, list<int> list);
};
