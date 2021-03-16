#pragma once
// take in tokens as a vector of tokens
// and parse

#include <errors.hpp>

class Parser
{
public:
	std::vector<Token> _tokens;
	Token _currentToken;
	int _tokenIndex;

	Parser(std::vector<Token> tokens);
};

