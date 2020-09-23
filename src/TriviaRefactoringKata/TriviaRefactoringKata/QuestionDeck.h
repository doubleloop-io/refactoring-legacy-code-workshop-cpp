#pragma once
#include <unordered_set>
#include <string>
#include "QuestionCategory.h"
#include <unordered_map>

class QuestionDeck
{
public:
	void fill_questions();
	std::string find_category_for(int place) const;
	std::string fetch_next_question(std::string category);

private:
	std::unordered_map<std::string, QuestionCategory> categories_ = {
		{ "Pop", QuestionCategory("Pop", { 0,4,8 }) },
		{ "Science", QuestionCategory("Science", { 1,5,9 })},
		{ "Sports", QuestionCategory("Sports", { 2,6,10 })},
		{ "Rock", QuestionCategory("Rock", { 3,7,11 })},
	};
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
