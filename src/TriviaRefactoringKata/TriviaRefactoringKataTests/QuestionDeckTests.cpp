#include "gtest/gtest.h"
#include "../TriviaRefactoringKata/QuestionDeck.h"

TEST(QuestionDeckTests, PopCategoryForPlaceZero) {
	QuestionDeck deck;
	auto category = deck.current_category(0);
	ASSERT_EQ(category, "Pop");
}
