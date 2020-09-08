﻿#include "gtest/gtest.h"
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

	deck.append_question_for("first foo", "foo");
	deck.append_question_for("first bar", "bar");

	EXPECT_EQ(deck.ask_question("foo"), "first foo");
	EXPECT_EQ(deck.ask_question("bar"), "first bar");
}

TEST(QuestionDeckTests, QuestionForUnknownCategory)
{
	QuestionDeck deck;

	deck.append_question_for("first bar", "bar");

	EXPECT_THROW(deck.ask_question("foo"), InvalidCategoryException);
}

TEST(QuestionDeckTests, MultipleAskedQuestionForSameCategory)
{
	QuestionDeck deck;
	
	deck.append_question_for("first bar", "bar");
	deck.append_question_for("second bar", "bar");

	EXPECT_EQ(deck.ask_question("bar"), "first bar");
	EXPECT_EQ(deck.ask_question("bar"), "second bar");
}

TEST(QuestionDeckTests, MultipleAskedQuestionForMixedCategory)
{
	QuestionDeck deck;

	deck.append_question_for("foo1", "foo");
	deck.append_question_for("foo2", "foo");
	deck.append_question_for("foo3", "foo");
	deck.append_question_for("bar1", "bar");
	deck.append_question_for("bar2", "bar");
	deck.append_question_for("baz1", "baz");

	EXPECT_EQ(deck.ask_question("foo"), "foo1");
	EXPECT_EQ(deck.ask_question("bar"), "bar1");
	EXPECT_EQ(deck.ask_question("bar"), "bar2");
	EXPECT_EQ(deck.ask_question("foo"), "foo2");
	EXPECT_EQ(deck.ask_question("baz"), "baz1");
	EXPECT_EQ(deck.ask_question("foo"), "foo3");
}
