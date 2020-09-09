#include "gtest/gtest.h"
#include "../TriviaRefactoringKata/GameRunner.h"
#include <fstream>
#include <experimental/filesystem>

class TestableGameRunner : public GameRunner
{
public:
	TestableGameRunner(const int seed)
		: seed_(seed)
	{
	}

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
auto app_golden_master = std::experimental::filesystem::current_path().append("app_golden_master.txt");

std::string read_content(std::string path)
{
	std::string line, content;
	std::ifstream file(path);
	while (std::getline(file, line))
	{
		content += line + "\r\n";
	}
	return  content;
}

TEST(ApplicationTests, GoldenMaster)
{
	{
		FileRedirect redirect(app_out_path.string());
		for (int i = 0; i < 100; ++i)
		{
			TestableGameRunner runner(i);
			runner.run(0, nullptr);
		}
	}

	auto actual = read_content(app_out_path.string());
	auto expected = read_content(app_golden_master.string());
	ASSERT_EQ(actual, expected);
}