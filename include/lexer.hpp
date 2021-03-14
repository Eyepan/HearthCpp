#pragma once

#include <token.hpp>

class Lexer
{
public:
	std::string _text;
	int _pos;
	char _currentChar;


	Lexer(std::string text);
	void advance();
	std::vector<Token> makeTokens();
	Token makeNumber();
};