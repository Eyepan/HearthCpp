#include <reparser.hpp>
#include <errors.hpp>

Parser::Parser(std::vector<Token> tokens) : _tokens(tokens)
{
	// loading all the tokens into the _stack
	for (Token i : _tokens)
	{
		_stack.push(i);
	}
}

void Parser::advance()
{
	_stack.pop();
}

Token Parser::factor()
{
	if ((_stack.peek()._type == TT_INT) || (_stack.peek()._type == TT_FLOAT))
	{
		return _stack.pop();
	}
	else if ((_stack.peek()._type == TT_RPAREN))
	{
		advance();
		Token expression = expr();
		if (_stack.peek()._type == TT_LPAREN)
		{
			return expression;
		}
		else
		{
			Error error(0, ErrorType::INVALID_SYNTAX_ERR, "Expected a paranthesis");
		}
	}
	else
	{
		Error error(0, ErrorType::INVALID_SYNTAX_ERR, "Expected an int/float token");
		std::cout << error.errorString << std::endl;
		system("pause");
		exit(0);
	}
}

Token Parser::term()
{
	Token right = factor();
	// checking if the next one is a valid token in this scenario
	if (!_stack.isEmpty())
	{
		if ((_stack.peek()._type != TT_PLUS) && (_stack.peek()._type != TT_MINUS) && (_stack.peek()._type != TT_MUL) && (_stack.peek()._type != TT_DIV) && (_stack.peek()._type != TT_RPAREN) && (_stack.peek()._type != TT_LPAREN))
		{
			Error error(_stack._top, ErrorType::INVALID_SYNTAX_ERR, "Expected +,-,*,/ token");
			std::cout << error.errorString << std::endl;
			system("pause");
			exit(0);
		}
	}
	while ((_stack.peek()._type == TT_MUL) || (_stack.peek()._type == TT_DIV))
	{
		Token op = _stack.pop();
		Token left = factor();
		// execution
		if (op._type == TT_MUL)
		{			
			if (left._type == TT_INT && right._type == TT_INT)
			{
				int eval = std::get<int>(left._data) * std::get<int>(right._data);
				right = Token(TT_INT, eval);
			}
			else if (left._type == TT_FLOAT && right._type == TT_FLOAT)
			{
				float eval = std::get<float>(left._data) * std::get<float>(right._data);
				right = Token(TT_FLOAT, eval);
			}
		}
		if (op._type == TT_DIV)
		{
			if (left._type == TT_INT && right._type == TT_INT)
			{
				int eval = std::get<int>(left._data) / std::get<int>(right._data);
				right = Token(TT_INT, eval);
			}
			else if (left._type == TT_FLOAT && right._type == TT_FLOAT)
			{
				float eval = std::get<float>(left._data) / std::get<float>(right._data);
				right = Token(TT_FLOAT, eval);
			}
		}	
		// _stack.push(left);
		// std::cout << _stack << std::endl;
	}
	return right;
}

Token Parser::expr()
{
	Token right = term();
	while ((_stack.peek()._type == TT_PLUS) || (_stack.peek()._type == TT_MINUS))
	{
		Token op = _stack.pop();
		Token left = term();

		// execution
		if (op._type == TT_PLUS)
		{
			if (left._type == TT_INT && right._type == TT_INT)
			{
				int eval = std::get<int>(left._data) + std::get<int>(right._data);
				right = Token(TT_INT, eval);
			}
			else if (left._type == TT_FLOAT && right._type == TT_FLOAT)
			{
				float eval = std::get<float>(left._data) + std::get<float>(right._data);
				right = Token(TT_FLOAT, eval);
			}
		}
		if (op._type == TT_MINUS)
		{
			if (left._type == TT_INT && right._type == TT_INT)
			{
				int eval = std::get<int>(left._data) - std::get<int>(right._data);
				right = Token(TT_INT, eval);
			}
			else if (left._type == TT_FLOAT && right._type == TT_FLOAT)
			{
				float eval = std::get<float>(left._data) - std::get<float>(right._data);
				right = Token(TT_FLOAT, eval);
			}
		}	
		// _stack.push(left);
		// std::cout << _stack << std::endl;
	}
	return right;
}

void Parser::parse()
{
	std::cout << expr();
}