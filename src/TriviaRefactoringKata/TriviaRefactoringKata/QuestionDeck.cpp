#include "QuestionDeck.h"
#include <sstream>
#include <algorithm>

using namespace std;

string QuestionDeck::make_question(string categoryName, int index)
{
	ostringstream oss(ostringstream::out);
	oss << categoryName << " Question " << index;
	return oss.str();
}

QuestionDeck::QuestionDeck()
	: pop_("Pop"),
	science_("Science"),
	sports_("Sports"),
	rock_("Rock")
{
	pop_.place_on(0);
	pop_.place_on(4);
	pop_.place_on(8);
	science_.place_on(1);
	science_.place_on(5);
	science_.place_on(9);
	sports_.place_on(2);
	sports_.place_on(6);
	sports_.place_on(10);
	rock_.place_on(3);
	rock_.place_on(7);
	rock_.place_on(11);
}

void QuestionDeck::fill_question_deck()
{
	for (int i = 0; i < 50; i++)
	{
		pop_.append_question(make_question("Pop", i));
		science_.append_question(make_question("Science", i));
		sports_.append_question(make_question("Sports", i));
		rock_.append_question(make_question("Rock", i));
	}
}

string QuestionDeck::category_on(int place)
{
	if (pop_.is_placed_on(place)) return pop_.name();
	if (science_.is_placed_on(place)) return science_.name();
	if (sports_.is_placed_on(place)) return sports_.name();
	if (rock_.is_placed_on(place)) return rock_.name();

	throw InvalidPlaceException(place);
}

string QuestionDeck::ask_question(string category)
{
	if (category == pop_.name()) return pop_.next_question();
	if (category == science_.name()) return science_.next_question();
	if (category == sports_.name()) return sports_.next_question();
	if (category == rock_.name()) return rock_.next_question();

	throw InvalidCategoryException(category);
}
