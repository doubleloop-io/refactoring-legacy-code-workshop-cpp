#pragma once
#include <list>

using namespace std;

class QuestionDeck
{
public:
	QuestionDeck();
	void fill_question_deck();
	string category_on(int place);
	string ask_question(string current_category);

private:
	list<string> popQuestions_;
	list<string> scienceQuestions_;
	list<string> sportsQuestions_;
	list<string> rockQuestions_;

	std::list<int> popPlaces_;
	std::list<int> sciencePlaces_;
	std::list<int> sportsPlaces_;
	std::list<int> rockPlaces_;

	string make_question(string categoryName, int index);
	bool list_contains(int value, list<int> list);
};
