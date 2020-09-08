#include "gtest/gtest.h"
#include "../TriviaRefactoringKata/GameRunner.h"
#include "FileRedirect.h"
#include <filesystem>

namespace fs = std::experimental::filesystem;

class TestableGameRunner : public GameRunner
{
public:
	void init_rand() override
	{
		srand(7);
	};

};

TEST(AppTest, Run)
{
	auto wd = fs::current_path().append("outputs").append("app_output.txt");
	FileRedirect fr(wd.string());
	TestableGameRunner runner;
	runner.run(0, nullptr);
}
