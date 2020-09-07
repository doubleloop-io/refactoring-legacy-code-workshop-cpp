#include "gtest/gtest.h"
#include "FizzBuzz.h"

using namespace std;

class FizzBuzzerTestFixture :public ::testing::TestWithParam<tuple<int, string>> { };

TEST_P(FizzBuzzerTestFixture, SingleNumber) {
	int number = std::get<0>(GetParam());
	const string expected = std::get<1>(GetParam());
	ASSERT_EQ(FizzBuzz::say(number), expected);
}

INSTANTIATE_TEST_CASE_P(
	FizzBuzzerTests, // -- random name
	FizzBuzzerTestFixture, // -- fixture name
	::testing::Values(
		// --
		make_tuple(3, "Fizz"),
		make_tuple(3 * 2, "Fizz"),
		// --
		make_tuple(5, "Buzz"),
		make_tuple(5 * 2, "Buzz"),
		// --
		make_tuple(15, "FizzBuzz"),
		make_tuple(15 * 2, "FizzBuzz"),
		// --
		make_tuple(7, "Bang"),
		make_tuple(7 * 2, "Bang"),
		make_tuple(7 * 3, "FizzBang"),
		// --
		make_tuple(1, "1"),
		make_tuple(2, "2"),
		make_tuple(4, "4"),
		make_tuple(8, "8")
	) // -- input data
);
