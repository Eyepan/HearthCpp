#pragma once

#include <stack.hpp>

class Parser
{
public:
	std::vector<Token> _tokens;
	// Token _currentToken;
	// int _tokenIndex;
	Stack _stack;
	

	Parser(std::vector<Token> tokens);
	void advance();

	Token factor();
	Token term();
	Token expr();

	void parse();
};