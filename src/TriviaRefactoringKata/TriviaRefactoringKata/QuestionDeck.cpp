#include "QuestionDeck.h"

std::string QuestionDeck::createRockQuestion(int index)
{
	char indexStr[127];
	sprintf_s(indexStr, "Rock Question %d", index);
	return indexStr;
}
