#include <lexer.hpp>

Lexer::Lexer(std::string text): _text(text), _currentPosition(-1)
{
	advance();
}


void Lexer::advance()
{
	_currentPosition++;
	if (_currentPosition < _text.length())
	{
		_currentChar = _text[_currentPosition];
	}
	else
	{
		_currentChar = NULL;
	}
}

void Lexer::makeTokens()
{
	// exiting
	if (_text == "quit")
	{
		std::cout << "EXITING HEARTH\n";
        exit(0);
	}
	while (_currentChar != NULL)
	{
		if (isdigit(_currentChar) || _currentChar == '.')
		{
			makeNumber();
			continue;
		}
		switch(_currentChar)
		{
			case ' ':
					advance();
					break;
			case '\t':
					advance();
					break;
			case '+':
					_tokens.push_back({TT_PLUS});
					advance();
					break;
			case '-':
					_tokens.push_back({TT_MINUS});
					advance();
					break;
			case '*':
					_tokens.push_back({TT_MUL});
					advance();
					break;
			case '/':
					_tokens.push_back({TT_DIV});
					advance();
					break;
			case '^':
					_tokens.push_back({TT_EXP});
					advance();
					break;
			case '%':
					_tokens.push_back({TT_MOD});
					advance();
					break;
			case '(':
					_tokens.push_back({TT_LPAREN});
					advance();
					break;
			case ')':
					_tokens.push_back({TT_RPAREN});
					advance();
					break;
			case '{':
					_tokens.push_back({TT_LBRACE});
					advance();
					break;
			case '}':
					_tokens.push_back({TT_RBRACE});
					advance();
					break;
			default:
					for (int i = 0; i < _currentPosition + 9; i++)
					{
						std::cout << " ";
					}
					std::cout << "^\n";
					std::cout << "ILLEGAL CHARACTER " << _currentChar << " in position " << _currentPosition << " of file <stdin>";
					_tokens.clear();
					return;
		}
	}

	// _tokens.push_back({TT_EOF});
}

// "Packaging numbers" into individual tokens.
// For example, without this function 5 + 4.63 will have 6 tokens, which is undesirable.
// With the help of this function, the expression will be condensed to 3 tokens.

void Lexer::makeNumber()
{
	std::string number;
	while (isdigit(_currentChar) || _currentChar == '.')
	{
		number += _currentChar;
		advance();
	}
	if (number.find('.') != std::string::npos)
	{
		_tokens.push_back({TT_FLOAT, stof(number)});
	}
	else
	{
		_tokens.push_back({TT_INT, stoi(number)});
	}
}

void Lexer::printTokens()
{
	for (auto i : _tokens)
	{
		std::cout << i << " ";
	}
	std::cout << "\n";
}

std::vector<Token> Lexer::getTokens()
{
	return _tokens;
}
