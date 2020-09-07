#include <string>

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
			return str;
		}
		if (number % 5 == 0)
		{
			auto str = "Buzz";
			value = str;
			return str;
		}
		if (number % 3 == 0)
		{
			auto str = "Fizz";
			value = str;
			return str;
		}
		return std::to_string(number);
	}
};