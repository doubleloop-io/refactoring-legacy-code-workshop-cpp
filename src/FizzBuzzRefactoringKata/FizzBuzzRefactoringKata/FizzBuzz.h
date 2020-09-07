#include <string>

class FizzBuzz
{
public:
	static std::string say(const int number)
	{
		std::string value = "";
		if (number % 3 == 0) value += "Fizz";
		if (number % 5 == 0) value += "Buzz";

		return std::empty(value) ? std::to_string(number) : value;
	}
};