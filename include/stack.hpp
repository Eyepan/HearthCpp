#pragma once

#include <token.hpp>

#define MAX_SIZE 128
class Stack
{
public:
	int _top;
	Token _st[1024];

	Stack();
	bool push(Token tk);
	Token pop();
	Token peek();
	bool isEmpty();
};

std::ostream& operator<<(std::ostream& os, Stack stack);
