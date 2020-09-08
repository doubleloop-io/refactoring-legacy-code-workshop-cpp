#include "gtest/gtest.h"
#include "../TriviaRefactoringKata/QuestionsCategory.h"

using namespace std;

TEST(QuestionsCategoryTests, CheckIsPlaced)
{
	QuestionsCategory questions("anything", { 1,2,3 });
	EXPECT_TRUE(questions.is_placed_on(1));
	EXPECT_TRUE(questions.is_placed_on(2));
	EXPECT_TRUE(questions.is_placed_on(3));
}

TEST(QuestionsCategoryTests, CheckIsNotPlaced)
{
	QuestionsCategory questions("anything", { 2,3 });
	EXPECT_FALSE(questions.is_placed_on(1));
	EXPECT_FALSE(questions.is_placed_on(4));
	EXPECT_FALSE(questions.is_placed_on(-3));
}
