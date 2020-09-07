#include <string>

class FizzBuzz
{
public:
	static std::string say(const int number)
	{
		if (number % 15 == 0)
		{
			auto str = "FizzBuzz";
			return str;
		}
		if (number % 5 == 0)
		{
			auto str = "Buzz";
			return str;
		}
		if (number % 3 == 0)
		{
			auto str = "Fizz";
			return str;
		}
		return std::to_string(number);
	}
};