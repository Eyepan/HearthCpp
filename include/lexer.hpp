#pragma once

#include <errors.hpp>

struct LexResult
{
	std::vector<Token> tokens;
	Error error;
};

class Lexer
{
public:
	std::string _text;
	int _pos;
	char _currentChar;


	Lexer(std::string text);
	void advance();
	LexResult makeTokens();
	Token makeNumber();
};