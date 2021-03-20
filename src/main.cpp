#include <lexer.hpp>
#include <reparser.hpp>
// get input from user into std::string text

int main()
{
	std::cout << "WELCOME TO HEARTH TESTING. TO EXIT ENTER 'quit'.\n";
	// system("pause");
	while (true)
	{
		std::cout << "\nhearth~$ ";
		std::string text;
		
		std::getline(std::cin, text);
		Lexer lexer(text);
		lexer.makeTokens();
		lexer.printTokens();
		if (lexer.getTokens().size() != 0)
		{
			Parser parser(lexer.getTokens());
			parser.parse();
		}
	}
}