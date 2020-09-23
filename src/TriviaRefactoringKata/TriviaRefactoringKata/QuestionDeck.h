#pragma once
#include <list>
#include <unordered_set>

class QuestionDeck
{
public:
	void fill_questions();
	std::string find_category_for(int place);
	std::string ask_question(std::string current_category);

private:
	std::list<std::string> popQuestions_;
	std::list<std::string> scienceQuestions_;
	std::list<std::string> sportsQuestions_;
	std::list<std::string> rockQuestions_;

	std::unordered_set<int> popPlaces_ = { 0,4,8 };
	std::unordered_set<int> sciencePlaces_ = { 1,5,9 };
	std::unordered_set<int> sportsPlaces_ = { 2,6,10 };
	std::unordered_set<int> rockPlaces_ = { 3,7,11 };
};
