#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <variant>

#define TT_INT		"INT"
#define TT_FLOAT	"FLOAT"
#define TT_PLUS		"PLUS"
#define TT_MINUS	"MINUS"
#define TT_MUL		"MUL"
#define TT_DIV		"DIV"
#define TT_LPAREN   "LPAREN"
#define TT_RPAREN	"RPAREN"
#define TT_EXP		"EXP"
#define TT_LSQB     "LSQB"
#define TT_RSQB     "RSQB"
#define TT_LBRACE   "LBRACE"
#define TT_LBRACE   "LBRACE"
#define TT_EOF		"EOF"
typedef std::variant<int, float, std::string> DATA;

// TOKENS STRUCT

struct Token
{
	std::string _type;
	DATA _data;
	Token();
	Token(std::string type, DATA data = "\0");
};
std::ostream& operator<<(std::ostream& os, Token& token);
