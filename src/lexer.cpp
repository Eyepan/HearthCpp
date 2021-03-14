#include <lexer.hpp>

std::string DIGITS = "0123456789";

// TOKENS

std::string TT_INT		= "INT";
std::string TT_FLOAT    = "FLOAT";
std::string TT_PLUS     = "PLUS";
std::string TT_MINUS    = "MINUS";
std::string TT_MUL      = "MUL";
std::string TT_DIV      = "DIV";
std::string TT_LPAREN   = "LPAREN";
std::string TT_RPAREN   = "RPAREN";
std::string TT_EXP      = "EXP";

Lexer::Lexer(std::string text)
{
	_text = text;
	_pos = -1;
	_currentChar = NULL;
	advance();
}

void Lexer::advance()
{
	_pos++;
	if (_pos < _text.length())
	{
		_currentChar = _text[_pos];
	}
	else
	{
		_currentChar = NULL;
	}
}

std::vector<Token> Lexer::makeTokens()
{
	std::vector<Token> _tokens;

	while (_currentChar != NULL)
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
				std::cout << "\nILLEGAL CHARACTER ERROR " << _currentChar;
				_tokens.clear();
				system("pause");
				exit(0);
		}
		
	}

	return _tokens;
}

Token Lexer::makeNumber()
{
	std::string number = "";
	int dotCount = 0;
	while (_currentChar != NULL && (isdigit(_currentChar) || _currentChar == '.'))
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