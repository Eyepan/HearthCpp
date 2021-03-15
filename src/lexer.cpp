#include <lexer.hpp>

std::string DIGITS = "0123456789";


Lexer::Lexer(std::string text)
{
	_text = text;
	_ss = std::stringstream(_text);
}

LexResult Lexer::makeTokens()
{
	std::string _token;
	int _pos = 0;
	while (_ss >> _token)
	{
		if (_token == "quit")
		{
			std::cout << "\nEXITING HEARTH\n";
			std::cout << "Press any key to continue...\n";
			std::cin.get();
			exit(0);
		}
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
			default:
				Error _error(_pos, ErrorType::ILLEGAL_CHAR_ERR, _token);
				return{ _tokens, _error };
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

void Lexer::printTokens()
{
	if (_tokens.size() > 0)
	{
		for (auto i : _tokens)
		{
			std::cout << i << " ";
		}
		std::cout << "\n";
	}
}