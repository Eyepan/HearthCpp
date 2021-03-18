#include <stack.hpp>

Stack::Stack(): _top(-1)
{
	
}

bool Stack::push(Token tk)
{
	if (_top >= (MAX_SIZE - 1))
	{
		std::cout << "STACK OVERFLOW" << std::endl;
		return false; 
	}
	_st[++_top] = tk;
	return true;
}

Token Stack::pop()
{
	if (_top < 0)
	{
		std::cout << "STACK UNDERFLOW" << std::endl;
		return Token(TT_EOF);
	}
	return _st[_top--];
}

Token Stack::peek()
{
	if (_top < 0)
	{
		return Token(TT_EOF);
	}
	return _st[_top];
}

bool Stack::isEmpty()
{
	return (_top < 0);
}

std::ostream& operator<<(std::ostream& os, Stack stack)
{
	while (!stack.isEmpty())
	{
		os << stack.pop() << " ";
	}
	return os;
}