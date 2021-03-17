#pragma once
// take in tokens as a vector of tokens
// and parse

#include <errors.hpp>

class Node
{
public:
	Node *_left = NULL;
	Node *_right = NULL;
	
	Token _token;

	Node(Token tk);
	Node(Token opToken, Node left, Node right);
};

void displayNodes(Node* root);

class Parser
{
public:
	std::vector<Token> _tokens;
	Token _currentToken;
	int _tokenIndex;

	Parser(std::vector<Token> tokens);
	void advance();
	Node factor();
	Node term();
	Node expr();
	
	Node parse();
};

