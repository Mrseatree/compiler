#pragma once
#ifndef CIFA_HEAD
#define CIFA_HEAD

#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

enum class TokenType
{
	//keyword
	PROGRAM,VAR,CONST,TYPE,FUNCTION,
	PROCEDURE,BEGIN,END,IF,THEN,
	WHILE,DO,FOR,TO,DOWNTO,
	REPEAT,UNTIL,CASE,OF,GOTO,WITH,
	IN,

	//operators
	PLUS,MINUS,MULTIPLY,DIVIDE,DIV,MOD,
	ASSIGN,
	EQUAL,NOT_EQUAL,LESS,LESS_EQUAL,GREATER,GREATER_EQUAL,
	AND,OR,NOT,
	BIT_AND,BIT_OR,BIT_NOT,BIT_XOR,
	RIGHT_SHIFT,LEFT_SHIFT,

	//delimeters
	SEMICOLON,COMMA,COLON,DOT,DOTDOT,
	LSQUARE_BRACKET,RSQUARE_BRACKET,LBRACKET,RBRACKET,LBRACE,RBRACE,
	QUATATION,DOUBLE_QUATATION,

	//literals
	INTEGER_LITERAL,REAL_LITERAL,STRING_LITERAL,IDENTIFIER,

	//special
	END_OF_FILE
};

vector<TokenType> types;
vector<string> keywords;

struct Token
{
	TokenType type;
	string value;
	int line;
	int column;

	Token(TokenType t, const string& v, int l, int c) :type(t), value(v), line(l), column(c) {}
};

void init_keywords();
#endif // !CIFA_HEAD
