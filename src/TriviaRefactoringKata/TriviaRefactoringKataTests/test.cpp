#include "gtest/gtest.h"
#include "../TriviaRefactoringKata/GameRunner.h"

TEST(DemoTest, SimpleAssertions) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}


TEST(ReplTest, GameRun)
{
	GameRunner::run(0, nullptr);
}