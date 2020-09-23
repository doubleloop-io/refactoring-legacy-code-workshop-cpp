#include "QuestionDeck.h"
#include <sstream>

static std::string create_question(int index, std::string category)
{
	std::ostringstream oss(std::ostringstream::out);
	oss << category + " Question " << index;
	return oss.str();
}

void QuestionDeck::fill_questions()
{
	for (auto& pair : categories_)
	{
		for (int i = 0; i < 50; i++)
		{
			pair.second.append_question(create_question(i, pair.first));
		}
	}
}

std::string QuestionDeck::find_category_for(int place) const
{
	for (auto& pair : categories_)
	{
		if (pair.second.places_contains(place))
			return pair.first;
	}
	throw PlaceNotFoundException(place);
}

std::string QuestionDeck::fetch_next_question(std::string category)
{
	auto it = categories_.find(category);
	if (it != categories_.end())
		return it->second.next_question();
	return "";
}

