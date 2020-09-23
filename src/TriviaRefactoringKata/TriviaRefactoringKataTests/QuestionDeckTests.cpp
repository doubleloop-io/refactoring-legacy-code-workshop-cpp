#include "gtest/gtest.h"
#include "../TriviaRefactoringKata/QuestionDeck.h"

class CurrentCategoryFixture : public ::testing::TestWithParam<std::tuple<int, std::string>> {};

TEST_P(CurrentCategoryFixture, LookupCategoryByPlace)
{
	int place = std::get<0>(GetParam());
	std::string expected = std::get<1>(GetParam());

	QuestionDeck deck;

	ASSERT_EQ(expected, deck.find_category_for(place));
}

INSTANTIATE_TEST_CASE_P(QuestionDeckTests, CurrentCategoryFixture, ::testing::Values(
	std::make_pair(0, "Pop"),
	std::make_pair(4, "Pop"),
	std::make_pair(8, "Pop"),
	std::make_pair(1, "Science"),
	std::make_pair(5, "Science"),
	std::make_pair(9, "Science"),
	std::make_pair(2, "Sports"),
	std::make_pair(6, "Sports"),
	std::make_pair(10, "Sports"),
	std::make_pair(3, "Rock"),
	std::make_pair(7, "Rock"),
	std::make_pair(11, "Rock")
));

TEST(QuestionDeckTests, CategoryForOutOfBoardPlace)
{
	QuestionDeck deck;
	EXPECT_EQ("Rock", deck.find_category_for(-1));
	EXPECT_EQ("Rock", deck.find_category_for(-123));
	EXPECT_EQ("Rock", deck.find_category_for(12));
	EXPECT_EQ("Rock", deck.find_category_for(123));
	EXPECT_EQ("Rock", deck.find_category_for(INT32_MAX));
}

// test unknown category

TEST(QuestionDeckTests, OneQuestionForCategory)
{
	QuestionDeck deck;

	deck.fill_questions();

	EXPECT_EQ("Pop Question 0", deck.fetch_next_question("Pop"));
	EXPECT_EQ("Science Question 0", deck.fetch_next_question("Science"));
	EXPECT_EQ("Sports Question 0", deck.fetch_next_question("Sports"));
	EXPECT_EQ("Rock Question 0", deck.fetch_next_question("Rock"));
}

TEST(QuestionDeckTests, ManyQuestionsForSameCategory)
{
	QuestionDeck deck;

	deck.fill_questions();

	EXPECT_EQ("Pop Question 0", deck.fetch_next_question("Pop"));
	EXPECT_EQ("Pop Question 1", deck.fetch_next_question("Pop"));
	EXPECT_EQ("Pop Question 2", deck.fetch_next_question("Pop"));
}

TEST(QuestionDeckTests, ManyQuestionsForMixedCategories)
{
	QuestionDeck deck;

	deck.fill_questions();

	EXPECT_EQ("Pop Question 0", deck.fetch_next_question("Pop"));
	EXPECT_EQ("Rock Question 0", deck.fetch_next_question("Rock"));
	EXPECT_EQ("Pop Question 1", deck.fetch_next_question("Pop"));
	EXPECT_EQ("Rock Question 1", deck.fetch_next_question("Rock"));
}

TEST(QuestionDeckTests, UnknownCategory)
{
	QuestionDeck deck;

	deck.fill_questions();

	EXPECT_EQ("", deck.fetch_next_question("any-unknown"));
}

// IGNORE: crash for debug assert
// TEST(QuestionDeckTests, AskQuestionsOnEmptyDeck)
// {
// 	QuestionDeck deck;
//
// 	const std::string any_category = "Pop";
//
// 	EXPECT_ANY_THROW(deck.fetch_next_question(any_category));
// }

// IGNORE
// TEST(QuestionDeckTests, EndOfQuestions)
// {
// 	QuestionDeck deck;
//
// 	const std::string any_category = "Pop";
//
// 	deck.fill_questions();
// 	for (int i = 0; i < 50; i++)
// 		deck.fetch_next_question(any_category);
//
// 	EXPECT_ANY_THROW(deck.fetch_next_question(any_category));
// }
