#include "gtest/gtest.h"
#include "../TriviaRefactoringKata/QuestionDeck.h"

class CurrentCategoryFixture : public ::testing::TestWithParam<std::tuple<int, std::string>> {};

TEST_P(CurrentCategoryFixture, LookupCategoryByPlace)
{
	int place = std::get<0>(GetParam());
	std::string expected = std::get<1>(GetParam());

	QuestionDeck deck;

	ASSERT_EQ(expected, deck.current_category(place));
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
	EXPECT_EQ("Rock", deck.current_category(-1));
	EXPECT_EQ("Rock", deck.current_category(-123));
	EXPECT_EQ("Rock", deck.current_category(12));
	EXPECT_EQ("Rock", deck.current_category(123));
	EXPECT_EQ("Rock", deck.current_category(INT32_MAX));
}

// test askquestion w/out fillquestions
// test unknown category
// test askk all questions + 1

TEST(QuestionDeckTests, OneQuestionForCategory)
{
	QuestionDeck deck;

	deck.fill_questions();

	EXPECT_EQ("Pop Question 0", deck.ask_question("Pop"));
	EXPECT_EQ("Science Question 0", deck.ask_question("Science"));
	EXPECT_EQ("Sports Question 0", deck.ask_question("Sports"));
	EXPECT_EQ("Rock Question 0", deck.ask_question("Rock"));
}

TEST(QuestionDeckTests, ManyQuestionsForSameCategory)
{
	QuestionDeck deck;

	deck.fill_questions();

	EXPECT_EQ("Pop Question 0", deck.ask_question("Pop"));
	EXPECT_EQ("Pop Question 1", deck.ask_question("Pop"));
	EXPECT_EQ("Pop Question 2", deck.ask_question("Pop"));
}

TEST(QuestionDeckTests, ManyQuestionsForMixedCategories)
{
	QuestionDeck deck;

	deck.fill_questions();

	EXPECT_EQ("Pop Question 0", deck.ask_question("Pop"));
	EXPECT_EQ("Rock Question 0", deck.ask_question("Rock"));
	EXPECT_EQ("Pop Question 1", deck.ask_question("Pop"));
	EXPECT_EQ("Rock Question 1", deck.ask_question("Rock"));
}
