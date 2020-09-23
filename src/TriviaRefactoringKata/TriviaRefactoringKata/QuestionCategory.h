#pragma once
#include <string>
#include <unordered_set>

class QuestionCategory
{
public:
	QuestionCategory(std::string name, const std::unordered_set<int> places);
	void append_question(const std::string question);
	std::string name() const;
	bool places_contains(int place) const;
	std::string next_question();

private:
	const std::string name_;
	const std::unordered_set<int> places_;
	std::list<std::string> questions_;
};
