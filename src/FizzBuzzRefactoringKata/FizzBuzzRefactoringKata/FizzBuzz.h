﻿#include <string>

class FizzBuzz
{
public:
	static std::string say(const int number)
	{
		std::string value = "";
		if (number % 15 == 0)
		{
			auto str = "FizzBuzz";
			value = str;
			return value;
		}
		if (number % 5 == 0)
		{
			auto str = "Buzz";
			value = str;
			return value;
		}
		if (number % 3 == 0)
		{
			auto str = "Fizz";
			value = str;
			return value;
		}
		return std::to_string(number);
	}
};