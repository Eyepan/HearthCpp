#include <iostream>
#include <lexer.hpp>

int main()
{
	std::cout << "WELCOME TO HEARTH v0.0.2" << std::endl;
	std::string text;
	bool running = true;
	while (running)
	{
		std::cout << "\nhearth > ";
		std::getline(std::cin, text);

		Lexer lexer(text);
		LexResult result  = lexer.makeTokens();
		if (result.error._errorType == ErrorType::SUCCESS)
		{
			for (auto i : result.tokens)
			{
				std::cout << i << " ";
			}
		}
		else
		{
			std::cout << result.error.errorString << std::endl;
		}
	}
}