#pragma once
#include <string>
#include <fstream>

class FileRedirect
{
public:
	FileRedirect(const std::string& path);
	~FileRedirect();

private:
	std::streambuf* original_;
	std::ofstream out_file_;
};
