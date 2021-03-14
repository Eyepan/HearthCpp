#include <iostream>
#include <lexer.hpp>

int main()
{
	std::cout << "WELCOME TO HEARTH v0.0.1" << std::endl;
	std::string text;
	bool running = true;
	while (running)
	{
		std::cout << "\nhearth > ";
		std::getline(std::cin, text);

		Lexer lexer(text);
		std::vector<Token> tokens = lexer.makeTokens();
		for (auto i : tokens)
		{
			std::cout << i << " ";
		}
	}
}