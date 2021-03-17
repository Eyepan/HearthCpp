#include <hearth.hpp>

Hearth::Hearth()
{
	std::cout << "WELCOME TO HEARTH v0.0.3" << std::endl;
}

void Hearth::mainLoop()
{
	std::string text;
	while (true)
	{
		std::cout << "hearth > ";
		std::getline(std::cin, text);

		Lexer lexer(text);
		LexResult result = lexer.makeTokens();
		if (result.error._errorType == ErrorType::SUCCESS)
		{
			lexer.printTokens();
		}
		else
		{
			std::cout << result.error.errorString << std::endl;
			continue;
		}
		Parser parser(result.tokens);
		Node ast = parser.parse();
		displayNodes(&ast);

	}
}
