#pragma once

#include <errors.hpp>

struct LexResult
{
	std::vector<Token> tokens;
	Error error;
};

// class Lexer
// {
// public:
// 	std::string _text;
// 	int _pos;
// 	char _currentChar;
// 
// 
// 	Lexer(std::string text);
// 	void advance();
// 	LexResult makeTokens();
// 	Token makeNumber();
// };

class Lexer
{
public:
	std::string _text;
	std::stringstream _ss;
	std::vector <Token> _tokens;

	Lexer(std::string text);
	LexResult makeTokens();
	void printTokens();
};