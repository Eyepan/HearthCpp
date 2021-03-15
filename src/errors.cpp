#include <errors.hpp>


Error::Error()
{
	_errorType = ErrorType::SUCCESS;
}
Error::Error(int position, ErrorType type, std::string details, std::string file)
{
	_position = position;
	_errorType = type;
	_details = details;
	for (int i = 0; i < _position + 9; i++)
	{
		std::cout << " ";
	}
	std::cout << "^\n";
	switch (_errorType)
	{
	case ErrorType::ILLEGAL_CHAR_ERR:
		errorString = "Illegal Character: '" + _details;
		errorString += "' in position " + std::to_string(_position) + " in file " + file;
		break;
	case ErrorType::INVALID_SYNTAX_ERR:
		errorString = "Invalid Syntax: '" + _details;
		errorString += " in position " + std::to_string(_position) + " in file " + file ;
		break;
	default:
		std::cerr << "Invalid Error Type" << std::endl;
	}
}

