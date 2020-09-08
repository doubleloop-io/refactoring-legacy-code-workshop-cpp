#include "gtest/gtest.h"
#include "../TriviaRefactoringKata/GameRunner.h"
#include "FileRedirect.h"
#include <filesystem>

namespace fs = std::experimental::filesystem;

class TestableGameRunner : public GameRunner
{
public:
	TestableGameRunner(int seed)
		: seed_(seed)
	{
	}

	void init_rand() override
	{
		srand(seed_);
	};

private:
	int seed_;
};

TEST(AppTest, Run)
{
	auto wd = fs::current_path().append("outputs").append("app_output.txt");
	FileRedirect fr(wd.string());
	TestableGameRunner runner(7);
	runner.run(0, nullptr);
}
