#include <token.hpp>

#ifdef _WIN32
void PAUSE()
{
	system("pause");
}
#else
void PAUSE()
{
	std::cin.ignore(1024, '\n');
	std::cout << "PRESS ENTER TO CONTINUE...";
	std::cin.get();
}
#endif



Token::Token() 
{
    // Welcome to Token()!
    // This is just a lounge!
    // Be my guest.
    // std::cout << "Token object has been instantiated!\n";
    // My life's purpose is complete!
    // Please hold on to your seatbelts and pray to all the non-existent gods.
}

Token::Token(std::string type, DATA data)
{
    _type = type;
	_data = data;
}

// To print out the tokens by overloading the cascading operator.
// In this format ==>  TYPE:DATA

std::ostream& operator<<(std::ostream& os, const Token& tk)
{
	if (tk._type == TT_INT)
    {
        os << tk._type << ":" << std::get<int>(tk._data);
    }
	else if (tk._type == TT_FLOAT)
	{
		os << tk._type << ":" << std::get<float>(tk._data);
	}
	else
	{
		os << tk._type;
	}

	return os;
}