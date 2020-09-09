#include "QuestionDeck.h"
#include <sstream>

std::string QuestionDeck::createRockQuestion(int index)
{
	char indexStr[127];
	sprintf_s(indexStr, "Rock Question %d", index);
	return indexStr;
}

void QuestionDeck::fill_questions()
{
	for (int i = 0; i < 50; i++)
	{
		std::ostringstream oss(std::ostringstream::out);
		oss << "Pop Question " << i;

		popQuestions_.push_back(oss.str());

		char str[255];
		sprintf_s(str, "Science Question %d", i);
		scienceQuestions_.push_back(str);

		char str1[255];
		sprintf_s(str1, "Sports Question %d", i);
		sportsQuestions_.push_back(str1);

		rockQuestions_.push_back(createRockQuestion(i));
	}
}
