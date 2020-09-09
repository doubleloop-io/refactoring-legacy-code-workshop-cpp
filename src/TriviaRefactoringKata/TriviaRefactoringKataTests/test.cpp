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
	TestableGameRunner(const int seed)
		: seed_(seed)
	{
	}

public:
	void init_rand() override
	{
		srand(seed_);
	}

private:
	const int seed_;
};


TEST(ReplTest, GameRun)
{
	auto p2 = std::experimental::filesystem::current_path().append("app_output.txt");
	std::ofstream os(p2);
	std::cout.rdbuf(os.rdbuf());

	TestableGameRunner runner(10);
	runner.run(0, nullptr);
}