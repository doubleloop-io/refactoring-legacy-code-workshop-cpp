#include "gtest/gtest.h"
#include "../TriviaRefactoringKata/GameRunner.h"
#include <fstream>
#include <experimental/filesystem>

TEST(DemoTest, SimpleAssertions) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

class TestableGameRunner : public GameRunner
{
public:
	void init_rand() override
	{
		srand(10);
	}
};


TEST(ReplTest, GameRun)
{
	auto p2 = std::experimental::filesystem::current_path().append("app_output.txt");
	std::ofstream os(p2);
	std::cout.rdbuf(os.rdbuf());

	TestableGameRunner runner;
	runner.run(0, nullptr);
}