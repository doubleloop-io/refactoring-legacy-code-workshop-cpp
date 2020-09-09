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

class FileRedirect
{
public:
	FileRedirect(std::string path)
	{
		output_file_.open(path);
		original_ = std::cout.rdbuf(output_file_.rdbuf());
	}

	~FileRedirect()
	{
		std::cout.rdbuf(original_);
		output_file_.close();
	}

private:
	std::ofstream output_file_;
	std::streambuf* original_;
};

auto app_out_path = std::experimental::filesystem::current_path().append("app_output.txt");

TEST(ReplTest, GameRun)
{
	FileRedirect redirect(app_out_path.string());
	TestableGameRunner runner(10);
	runner.run(0, nullptr);
}