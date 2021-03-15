#include <lexer.hpp>

std::string DIGITS = "0123456789";


Lexer::Lexer(std::string text)
{
	_text = text;
	_ss = std::stringstream(_text);
}

// void Lexer::advance()
// {
// 	_pos++;
// 	if (_pos < (int)_text.length())
// 	{
// 		_currentChar = _text[_pos];
// 	}
// 	else
// 	{
// 		_currentChar = '\0';
// 	}
// }


LexResult Lexer::makeTokens()
{
	std::string _token;
	int _pos = 0;
	while (_ss >> _token)
	{
		if (DIGITS.find(_token[0]) != std::string::npos)
		{
			if (_token.find('.') != std::string::npos)
			{
				_tokens.push_back({ "FLOAT", std::stof(_token) });
				_pos += _token.size() + 1;
				continue;
			}
			else
			{
				_tokens.push_back({ "INT", std::stoi(_token) });
				_pos += _token.size() + 1;
				continue;
			}
		}

		// check for single tokens
		if (_token.size() == 1)
		{
			switch (_token[0])
			{
			case ' ':
				_pos += _token.size() + 1;
				continue;
			case '\t':
				_pos += _token.size() + 1;
				continue;
			case '+':
				_tokens.push_back({ "PLUS" });
				_pos += _token.size() + 1;
				continue;
			case '-':
				_tokens.push_back({ "MINUS" });
				_pos += _token.size() + 1;
				continue;
			case '*':
				_tokens.push_back({ "MUL" });
				_pos += _token.size() + 1;
				continue;
			case '/':
				_tokens.push_back({ "DIV" });
				_pos += _token.size() + 1;
				continue;
			case '(':
				_tokens.push_back({ "LPAREN" });
				_pos += _token.size() + 1;
				continue;
			case ')':
				_tokens.push_back({ "RPAREN" });
				_pos += _token.size() + 1;
				continue;
			case '^':
				_tokens.push_back({ "EXP" });
				_pos += _token.size() + 1;
				continue;
			case '[':
				_tokens.push_back({ "LSQB" });
				_pos += _token.size() + 1;
				continue;
			case ']':
				_tokens.push_back({ "RSQB" });
				_pos += _token.size() + 1;
				continue;
			case '{':
				_tokens.push_back({ "LBRACE" });
				_pos += _token.size() + 1;
				continue;
			case '}':
				_tokens.push_back({ "RBRACE" });
				_pos += _token.size() + 1;
				continue;

				// seriously bad code
			case 'x':
				std::cout << "\nEXITING HEARTH\n";
				exit(0);
				break;
			}
		}
		else
		{
			// Illegal Character Error
			Error _error(_pos, ErrorType::ILLEGAL_CHAR_ERR, _token);
			return{ _tokens, _error };
		}
	}
	Error success;
	return { _tokens, success };
}
// LexResult Lexer::makeTokens()
// {
// 	std::vector<Token> _tokens;
// 	
// 
// 	while (_currentChar != '\0')
// 	{
// 		if (DIGITS.find(_currentChar) != std::string::npos)
// 		{
// 			_tokens.push_back(makeNumber());
// 			continue;
// 		}
// 		switch (_currentChar)
// 		{
// 			case ' ':
// 				advance();
// 				break;
// 			case '\t':
// 				break;
// 			case '+':
// 				_tokens.push_back(Token(TT_PLUS)); 
// 				advance();
// 				break;
// 			case '-':
// 				_tokens.push_back(Token(TT_MINUS));
// 				advance();
// 				break;
// 			case '*':
// 				_tokens.push_back(Token(TT_MUL));
// 				advance();
// 				break;
// 			case '/':
// 				_tokens.push_back(Token(TT_DIV));
// 				advance();
// 				break;
// 			case '(':
// 				_tokens.push_back(Token(TT_LPAREN));
// 				advance();
// 				break;
// 			case ')':
// 				_tokens.push_back(Token(TT_RPAREN));
// 				advance();
// 				break;
// 			case '^':
// 				_tokens.push_back(Token(TT_EXP));
// 				advance();
// 				break;
// 			case 'x':
// 				std::cout << "\nEXITING HEARTH\n";
// 				exit(0);
// 				break;
// 			default:
// 				Error _error(_pos, ErrorType::ILLEGAL_CHAR_ERR, std::string(1, _currentChar));
// 				return{ _tokens, _error };
// 		}
// 		
// 	}
// 	Error success;
// 	return { _tokens, success };
// }

// Token Lexer::makeNumber()
// {
// 	std::string number = "";
// 	int dotCount = 0;
// 	while (_currentChar != '\0' && (isdigit(_currentChar) || _currentChar == '.'))
// 	{
// 		if (_currentChar == '.')
// 		{
// 			if (dotCount == 1) break;
// 			dotCount++;
// 		}
// 		number.push_back(_currentChar);
// 
// 		advance();
// 	}
// 
// 	if (dotCount == 0) 
// 	{
// 		return Token(TT_INT, stoi(number));
// 	}
// 	else
// 	{
// 		return Token(TT_FLOAT, stof(number));
// 	}
// }