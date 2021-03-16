#include <token.hpp>

Token::Token()
{

}

Token::Token(std::string type, std::variant<int, float, std::string> data)
{
	_type = type;
	_data = data;
}


std::ostream& operator<<(std::ostream& os, Token& token)
{
	if (token._data == (std::variant<int, float, std::string>)"\0")
	{
		os << token._type;
	}
	else
	{
		switch (token._data.index())
		{
		case 0:
			// integer
			os << token._type << ":" << (int&)token._data;
			break;
		case 1:
			// float
			os << token._type << ":" << (float&)token._data;
			break;
		case 2:
			// string
			os << token._type << ":" << (std::string&)token._data;
			break;
		}
	}

	return os;
}