#include <string>

class FizzBuzz
{
public:
	static std::string say(const int number)
	{
		if (number % 15 == 0) return "FizzBuzz";
		if (number % 7 == 0)  return "Bang";
		if (number % 5 == 0)  return "Buzz";
		if (number % 3 == 0)  return "Fizz";
		return std::to_string(number);
	}
};