#include "gtest/gtest.h"
#include "../TriviaRefactoringKata/QuestionDeck.h"

using namespace std;

class QuestionDeckTestsFixture : public ::testing::TestWithParam<tuple<int, string>> {};

TEST_P(QuestionDeckTestsFixture, LookupCategoryByPlace) {
	int place = get<0>(GetParam());
	string expected = get<1>(GetParam());

	QuestionDeck deck;
	auto category = deck.category_on(place);
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

TEST(QuestionDeckTests, CategoryForOutOfBoardPlace)
{
	QuestionDeck deck;
	EXPECT_THROW(deck.category_on(12), InvalidPlaceException);
	EXPECT_THROW(deck.category_on(12), InvalidPlaceException);
	EXPECT_THROW(deck.category_on(123), InvalidPlaceException);
	EXPECT_THROW(deck.category_on(INT32_MAX), InvalidPlaceException);
	EXPECT_THROW(deck.category_on(-1), InvalidPlaceException);
}

TEST(QuestionDeckTests, FirstAskedQuestionForCategory)
{
	QuestionDeck deck;
	deck.fill_question_deck();
	EXPECT_EQ(deck.ask_question("Pop"), "Pop Question 0");
	EXPECT_EQ(deck.ask_question("Science"), "Science Question 0");
	EXPECT_EQ(deck.ask_question("Sports"), "Sports Question 0");
	EXPECT_EQ(deck.ask_question("Rock"), "Rock Question 0");
}

TEST(QuestionDeckTests, QuestionForUnknownCategory)
{
	QuestionDeck deck;
	deck.fill_question_deck();
	EXPECT_EQ(deck.ask_question("foo"), "");
	EXPECT_EQ(deck.ask_question("pop"), "");
	EXPECT_EQ(deck.ask_question("pOp"), "");
}

TEST(QuestionDeckTests, MultipleAskedQuestionForSameCategory)
{
	QuestionDeck deck;
	deck.fill_question_deck();
	EXPECT_EQ(deck.ask_question("Pop"), "Pop Question 0");
	EXPECT_EQ(deck.ask_question("Pop"), "Pop Question 1");
	EXPECT_EQ(deck.ask_question("Pop"), "Pop Question 2");
	EXPECT_EQ(deck.ask_question("Pop"), "Pop Question 3");
}

TEST(QuestionDeckTests, MultipleAskedQuestionForMixedCategory)
{
	QuestionDeck deck;
	deck.fill_question_deck();
	EXPECT_EQ(deck.ask_question("Pop"), "Pop Question 0");
	EXPECT_EQ(deck.ask_question("Sports"), "Sports Question 0");
	EXPECT_EQ(deck.ask_question("Sports"), "Sports Question 1");
	EXPECT_EQ(deck.ask_question("Pop"), "Pop Question 1");
	EXPECT_EQ(deck.ask_question("Rock"), "Rock Question 0");
	EXPECT_EQ(deck.ask_question("Pop"), "Pop Question 2");
}
