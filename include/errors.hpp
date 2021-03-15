#pragma once
#include <token.hpp>

enum class ErrorType
{
	ILLEGAL_CHAR_ERR,
	INVALID_SYNTAX_ERR,
	SUCCESS
};

class Error
{
public:
	int _position = -1;
	ErrorType _errorType;
	std::string _details;

	Error();
	Error(int position, ErrorType type, std::string details, std::string file = "<stdin>");
	std::string errorString;
};