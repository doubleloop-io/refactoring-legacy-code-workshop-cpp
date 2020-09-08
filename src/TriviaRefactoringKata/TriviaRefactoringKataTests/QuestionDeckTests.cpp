#include "gtest/gtest.h"
#include "../TriviaRefactoringKata/QuestionDeck.h"

using namespace std;

class QuestionDeckTestsFixture : public ::testing::TestWithParam<tuple<int, string>> {};

TEST_P(QuestionDeckTestsFixture, LookupCategoryByPlace) {
	int place = get<0>(GetParam());
	string expected = get<1>(GetParam());

	QuestionDeck deck;
	auto category = deck.current_category(place);
	ASSERT_EQ(category, expected);
}

INSTANTIATE_TEST_CASE_P(
	QuestionDeckTests,
	QuestionDeckTestsFixture,
	::testing::Values(
		// --
		make_pair(0, "Pop"),
		make_pair(4, "Pop"),
		make_pair(8, "Pop"),
		// --
		make_pair(1, "Science"),
		make_pair(5, "Science"),
		make_pair(9, "Science"),
		// --
		make_pair(2, "Sports"),
		make_pair(6, "Sports"),
		make_pair(10, "Sports"),
		// --
		make_pair(3, "Rock"),
		make_pair(7, "Rock"),
		make_pair(11, "Rock")
	)
);
