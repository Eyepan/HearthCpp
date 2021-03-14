#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <variant>

// TOKENS STRUCT

struct Token
{
	std::string _type;
	std::variant<int, float, std::string> _data;
	
	Token(std::string type, std::variant<int, float, std::string> data = (std::variant<int, float, std::string>)"\0");
};
std::ostream& operator<<(std::ostream& os, Token& token);
