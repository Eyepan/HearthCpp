#include <errors.hpp>


#ifdef _WIN32
void PAUSE()
{
	system("pause");
}
#else
void PAUSE()
{
	// std::cin.ignore(1024, '\n');
	std::cout << "Press enter to continue...";
	std::cin.get();
}
#endif

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
		errorString = "Illegal Character: '" + std::string(1, _details[0]) + "' in token '" + _details;
		errorString += "' in position " + std::to_string(_position) + " in file " + file;
		break;
	case ErrorType::INVALID_SYNTAX_ERR:
		errorString = "Invalid Syntax: '" + _details;
		errorString += " in position " + std::to_string(_position) + " in file " + file ;
		break;
	default:
		std::cerr << "Invalid Error Type" << std::endl;
	}

	std::cout << errorString << std::endl;
	PAUSE();
	exit(0);
}

