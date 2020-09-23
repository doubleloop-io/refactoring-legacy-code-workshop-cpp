#include "gtest/gtest.h"
#include "../TriviaRefactoringKata/QuestionCategory.h"

TEST(QuestionCategoryTests, CheckOnMyPlace)
{
	QuestionCategory category("any-name", { 1, 2 });
	EXPECT_TRUE(category.is_placed_on(1));
	EXPECT_TRUE(category.is_placed_on(2));
}

TEST(QuestionCategoryTests, CheckNotOnMyPlace)
{
	QuestionCategory category("any-name", { 555, 23 });
	EXPECT_FALSE(category.is_placed_on(1));
	EXPECT_FALSE(category.is_placed_on(2));
}

TEST(QuestionCategoryTests, ManyNextQuestions)
{
	QuestionCategory category("any-name", {});

	category.append_question("first");
	category.append_question("second");

	EXPECT_EQ("first", category.next_question());
	EXPECT_EQ("second", category.next_question());
}
