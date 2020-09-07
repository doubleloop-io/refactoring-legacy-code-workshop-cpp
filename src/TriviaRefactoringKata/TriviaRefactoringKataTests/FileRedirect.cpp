#include "FileRedirect.h"
#include <iostream>

FileRedirect::FileRedirect(const std::string& path)
{
	out_file_.open(path);
	original_ = std::cout.rdbuf(out_file_.rdbuf());
}

FileRedirect::~FileRedirect()
{
	std::cout.rdbuf(original_);
	out_file_.close();
}
