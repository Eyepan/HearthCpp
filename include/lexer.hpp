#pragma once


#include <token.hpp>

// std::vector<Token> _tokens;
// std::string _text; 
// int _currentPosition = -1;
// Lexer::advance()
// Lexer::makeTokens()
// Lexer::printTokens()

class Lexer
{
public:

	std::vector<Token> _tokens;
	std::string _text; 
	int _currentPosition = -1;
	char _currentChar;


	Lexer(std::string text);
	void advance();
	void makeTokens();
	void makeNumber();
	void printTokens();

	std::vector<Token> getTokens();
};