#include <lexer.hpp>

std::string DIGITS = "0123456789";


Lexer::Lexer(std::string text)
{
	_text = text;
	_pos = -1;
	_currentChar = '\0';
	advance();
}

void Lexer::advance()
{
	_pos++;
	if (_pos < (int)_text.length())
	{
		_currentChar = _text[_pos];
	}
	else
	{
		_currentChar = '\0';
	}
}

LexResult Lexer::makeTokens()
{
	std::vector<Token> _tokens;
	

	while (_currentChar != '\0')
	{
		if (DIGITS.find(_currentChar) != std::string::npos)
		{
			_tokens.push_back(makeNumber());
			continue;
		}
		switch (_currentChar)
		{
			case ' ':
				advance();
				break;
			case '\t':
				break;
			case '+':
				_tokens.push_back(Token(TT_PLUS)); 
				advance();
				break;
			case '-':
				_tokens.push_back(Token(TT_MINUS));
				advance();
				break;
			case '*':
				_tokens.push_back(Token(TT_MUL));
				advance();
				break;
			case '/':
				_tokens.push_back(Token(TT_DIV));
				advance();
				break;
			case '(':
				_tokens.push_back(Token(TT_LPAREN));
				advance();
				break;
			case ')':
				_tokens.push_back(Token(TT_RPAREN));
				advance();
				break;
			case '^':
				_tokens.push_back(Token(TT_EXP));
				advance();
				break;
			case 'x':
				std::cout << "\nEXITING HEARTH\n";
				exit(0);
				break;
			default:
				Error _error(_pos, ErrorType::ILLEGAL_CHAR_ERR, std::string(1, _currentChar));
				return{ _tokens, _error };
		}
		
	}
	Error success;
	return { _tokens, success };
}

Token Lexer::makeNumber()
{
	std::string number = "";
	int dotCount = 0;
	while (_currentChar != '\0' && (isdigit(_currentChar) || _currentChar == '.'))
	{
		if (_currentChar == '.')
		{
			if (dotCount == 1) break;
			dotCount++;
		}
		number.push_back(_currentChar);

		advance();
	}

	if (dotCount == 0) 
	{
		return Token(TT_INT, number);
	}
	else
	{
		return Token(TT_FLOAT, number);
	}
}