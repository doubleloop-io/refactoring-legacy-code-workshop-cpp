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
		make_pair(0, "Pop"),
		make_pair(4, "Pop"),
		make_pair(8, "Pop")
	)
);

TEST(QuestionDeckTests, PopCategoryForPlaceZero) {
	QuestionDeck deck;
	auto category = deck.current_category(0);
	ASSERT_EQ(category, "Pop");
}

TEST(QuestionDeckTests, PopCategoryForPlaceFour) {
	QuestionDeck deck;
	auto category = deck.current_category(4);
	ASSERT_EQ(category, "Pop");
}
