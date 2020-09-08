#include "gtest/gtest.h"
#include "../TriviaRefactoringKata/GameRunner.h"
#include "FileRedirect.h"
#include <filesystem>

namespace fs = std::experimental::filesystem;

TEST(AppTest, Run)
{
	auto wd = fs::current_path().append("outputs").append("app_output.txt");
	FileRedirect fr(wd.string());

	for (size_t i = 0; i < 1; i++)
	{
		GameRunner::run(15);
	}
}
