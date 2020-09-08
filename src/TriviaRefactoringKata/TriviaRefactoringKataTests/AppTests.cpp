#include "gtest/gtest.h"
#include "../TriviaRefactoringKata/GameRunner.h"
#include "FileRedirect.h"
#include <filesystem>

namespace fs = std::experimental::filesystem;

auto run_output_path = fs::current_path().append("outputs").append("app_output.txt");
auto golden_master_output_path = fs::current_path().append("app_output.golden_master.txt");

std::string read_content(fs::path path)
{
	std::string line, content;
	std::ifstream file(path);
	if (!file.is_open()) return "";

	while (std::getline(file, line))
	{
		content += line + '\n';
	}
	return content;
}

void game_runs_for(int count)
{
	for (size_t i = 0; i < 1000; i++)
	{
		// seed distribution 
		// via linear function
		// f(x) = ax+b,
		auto seed = 3645 * i + 42;
		GameRunner::run(seed);
	}
}

TEST(AppTest, GoldenMaster)
{
	{
		FileRedirect fr(run_output_path.string());
		game_runs_for(1000);
	}

	auto actual = read_content(run_output_path);
	auto expected = read_content(golden_master_output_path);

	ASSERT_EQ(actual, expected);
}
