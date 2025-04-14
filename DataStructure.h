#pragma once
#ifndef CIFA_HEAD
#define CIFA_HEAD

#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<typeinfo>
#include<unordered_map>

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
	INTEGER_LITERAL,REAL_LITERAL,STRING_LITERAL,IDENTIFIER,BOOLEAN_LITERAL,

	//special
	END_OF_FILE
};

extern int has_num;

extern unordered_map<TokenType, string>type_name;

struct Token
{
	TokenType type;
	string value;
	int line;
	int column;

	Token(TokenType t, const string& v, int l, int c) :type(t), value(v), 
		line(l+1), column(c - static_cast<int>(value.size()) + 1) {
		has_num = 0;
		cout << this->value << " type: " << type_name[this->type] << endl;
	}
};

extern FILE* fp;
extern int line, col,last_col;
extern char c;
extern string token;
extern vector<Token>token_stream;
extern vector<TokenType> types;
extern vector<string> keywords;


vector<Token> lex();
void init_keywords();
void get_nbc();
void get_char();
void restract();
int check(string word);
#endif // !CIFA_HEAD;
