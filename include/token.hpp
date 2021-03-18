#pragma once

#include <iostream>
#include <vector>
#include <variant>
#include <string>

// Number Literal tokens
#define TT_INT		"INT"
#define TT_FLOAT	"FLOAT"

// Arithmetic Tokens
#define TT_PLUS		"PLUS"
#define TT_MINUS	"MINUS"
#define TT_MUL		"MUL"
#define TT_DIV		"DIV"
#define TT_EXP		"EXP"
#define TT_MOD      "MOD"
#define TT_LPAREN   "LPAREN"
#define TT_RPAREN	"RPAREN"

// Placeholder tokens

#define TT_LBRACE   "LBRACE"
#define TT_RBRACE   "RBRACE"
#define TT_LSQB     "LSQB"
#define TT_RSQB     "RSQB"
#define TT_EOF		"EOF"


typedef std::variant<int, float, std::string> DATA;

class Token
{
public:
	std::string _type;
	DATA 		_data;

	Token();
	Token(std::string type, DATA data = "\0");
};



std::ostream& operator<<(std::ostream& os, const Token& tk);


