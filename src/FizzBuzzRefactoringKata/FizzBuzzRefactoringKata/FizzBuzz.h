#include <string>

class FizzBuzz
{
public:
	static std::string say(const int number)
	{
		std::string str;
		if (number % 3 == 0) str += "Fizz";
		if (number % 5 == 0) str += "Buzz";
		if (number % 7 == 0) str += "Bang";

		return empty(str) ? std::to_string(number) : str;
	}
};