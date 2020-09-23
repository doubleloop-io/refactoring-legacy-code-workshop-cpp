#pragma once
#include <list>
#include <unordered_set>
#include <string>

class QuestionDeck
{
public:
	void fill_questions();
	std::string find_category_for(int place) const;
	std::string fetch_next_question(std::string category);

private:
	std::list<std::string> popQuestions_;
	std::list<std::string> scienceQuestions_;
	std::list<std::string> sportsQuestions_;
	std::list<std::string> rockQuestions_;

	const std::unordered_set<int> popPlaces_ = { 0,4,8 };
	const std::unordered_set<int> sciencePlaces_ = { 1,5,9 };
	const std::unordered_set<int> sportsPlaces_ = { 2,6,10 };
	const std::unordered_set<int> rockPlaces_ = { 3,7,11 };
};

class PlaceNotFoundException : public std::exception
{
public:
	PlaceNotFoundException(int place)
		: msg_("Not found place: " + std::to_string(place)) {}

private:
	std::string msg_;

	char const* what() const override
	{
		return  msg_.c_str();
	}
};
