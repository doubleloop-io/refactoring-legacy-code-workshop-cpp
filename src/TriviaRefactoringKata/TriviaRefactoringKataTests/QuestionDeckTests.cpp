#include "gtest/gtest.h"
#include "../TriviaRefactoringKata/QuestionDeck.h"

using namespace std;

TEST(QuestionDeckTestsFixture, SameCategoryOnManyPlaces) {
	QuestionDeck deck;

	deck.place_category_on(1, "foo");
	deck.place_category_on(22, "foo");

	EXPECT_EQ(deck.category_on(1), "foo");
	EXPECT_EQ(deck.category_on(22), "foo");
}

TEST(QuestionDeckTestsFixture, DifferentCategoriesOnManyPlaces) {
	QuestionDeck deck;

	deck.place_category_on(1, "foo");
	deck.place_category_on(22, "bar");

	EXPECT_EQ(deck.category_on(1), "foo");
	EXPECT_EQ(deck.category_on(22), "bar");
}

TEST(QuestionDeckTests, CategoryForEmptyPlace)
{
	QuestionDeck deck;

	deck.place_category_on(1, "foo");
	deck.place_category_on(22, "bar");

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
	EXPECT_THROW(deck.ask_question("foo"), InvalidCategoryException);
	EXPECT_THROW(deck.ask_question("pop"), InvalidCategoryException);
	EXPECT_THROW(deck.ask_question("pOp"), InvalidCategoryException);
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
