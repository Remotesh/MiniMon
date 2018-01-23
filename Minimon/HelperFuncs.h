#pragma once

char* EntIDToChar(const int number)
{
	char* returnCharacters = new char[1];
	char character = '0' + (number);

	returnCharacters[0] = character;

	return returnCharacters;
}