#include "gtest/gtest.h"
#include "../TriviaRefactoringKata/QuestionDeck.h"

TEST(QuestionDeckTests, PopCategoryForPlaceZero) {
	QuestionDeck deck;
	auto category = deck.current_category(0);
	ASSERT_EQ(category, "Pop");
}

TEST(QuestionDeckTests, PopCategoryForPlaceFour) {
	QuestionDeck deck;
	auto category = deck.current_category(4);
	ASSERT_EQ(category, "Pop");
}
