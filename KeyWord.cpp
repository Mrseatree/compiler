#include"DataStructure.h"
void init_keywords()
{
	keywords.push_back("program");
	keywords.push_back("var");
	keywords.push_back("const");
	keywords.push_back("type");
	keywords.push_back("function");
	keywords.push_back("procedure");
	keywords.push_back("begin");
	keywords.push_back("end");
	keywords.push_back("if");
	keywords.push_back("then");
	keywords.push_back("while");
	keywords.push_back("do");
	keywords.push_back("for");
	keywords.push_back("to");
	keywords.push_back("downto");
	keywords.push_back("repeat");
	keywords.push_back("until");
	keywords.push_back("case");
	keywords.push_back("of");
	keywords.push_back("goto");
	keywords.push_back("with");
	keywords.push_back("in");

	keywords.push_back("true");
	keywords.push_back("false");

	types.push_back(TokenType::PROGRAM);
	types.push_back(TokenType::VAR);
	types.push_back(TokenType::CONST);
	types.push_back(TokenType::TYPE);
	types.push_back(TokenType::FUNCTION);
	types.push_back(TokenType::PROCEDURE);
	types.push_back(TokenType::BEGIN);
	types.push_back(TokenType::END);
	types.push_back(TokenType::IF);
	types.push_back(TokenType::THEN);
	types.push_back(TokenType::WHILE);
	types.push_back(TokenType::DO);
	types.push_back(TokenType::FOR);
	types.push_back(TokenType::TO);
	types.push_back(TokenType::DOWNTO);
	types.push_back(TokenType::REPEAT);
	types.push_back(TokenType::UNTIL);
	types.push_back(TokenType::CASE);
	types.push_back(TokenType::OF);
	types.push_back(TokenType::GOTO);
	types.push_back(TokenType::WITH);
	types.push_back(TokenType::IN);

	types.push_back(TokenType::BOOLEAN_LITERAL);
	types.push_back(TokenType::BOOLEAN_LITERAL);

	type_name[TokenType::PROGRAM] = "PROGRAM";
	type_name[TokenType::VAR] = "VAR";
	type_name[TokenType::CONST] = "CONST";
	type_name[TokenType::TYPE] = "TYPE"; 
	type_name[TokenType::FUNCTION] = "FUNCTION";
	type_name[TokenType::PROCEDURE] = "PROCEDURE";
	type_name[TokenType::BEGIN] = "BEGIN";
	type_name[TokenType::END] = "END";
	type_name[TokenType::IF] = "IF";
	type_name[TokenType::THEN] = "THEN";
	type_name[TokenType::WHILE] = "WHILE";
	type_name[TokenType::DO] = "DO";
	type_name[TokenType::FOR] = "FOR";
	type_name[TokenType::TO] = "TO";
	type_name[TokenType::DOWNTO] = "DOWNTO";
	type_name[TokenType::REPEAT] = "REPEAT";
	type_name[TokenType::UNTIL] = "UNTIL";
	type_name[TokenType::CASE] = "CASE";
	type_name[TokenType::OF] = "OF";
	type_name[TokenType::GOTO] = "GOTO";
	type_name[TokenType::WITH] = "WITH";
	type_name[TokenType::IN] = "IN";

		//operators
	type_name[TokenType::PLUS] = "PLUS";
	type_name[TokenType::MINUS] = "MINUS";
	type_name[TokenType::MULTIPLY] = "MULTIPLY";
	type_name[TokenType::DIVIDE] = "DIVIDE";
	type_name[TokenType::DIV] = "DIV";
	type_name[TokenType::MOD] = "MOD";
	type_name[TokenType::ASSIGN] = "ASSIGN";
	type_name[TokenType::EQUAL] = "EQUAL";
	type_name[TokenType::NOT_EQUAL] = "NOT_EQUAL";
	type_name[TokenType::LESS] = "LESS";
	type_name[TokenType::LESS_EQUAL] = "LESS_EQUAL";
	type_name[TokenType::GREATER] = "GREATER";
	type_name[TokenType::GREATER_EQUAL] = "GREATER_EQUAL";
	type_name[TokenType::AND] = "AND";
	type_name[TokenType::OR] = "OR";
	type_name[TokenType::NOT] = "NOT";
	type_name[TokenType::BIT_AND] = "BIT_AND";
	type_name[TokenType::BIT_OR] = "BIT_OR";
	type_name[TokenType::BIT_NOT] = "BIT_NOT";
	type_name[TokenType::BIT_XOR] = "BIT_XOR";
	type_name[TokenType::RIGHT_SHIFT] = "RIGHT_SHIFT";
	type_name[TokenType::LEFT_SHIFT] = "LEFT_SHIFT";

		//delimeters
	type_name[TokenType::SEMICOLON] = "SEMICOLON";
	type_name[TokenType::COMMA] = "COMMA";
	type_name[TokenType::COLON] = "COLON";
	type_name[TokenType::DOT] = "DOT";
	type_name[TokenType::DOTDOT] = "DOTDOT";
	type_name[TokenType::LSQUARE_BRACKET] = "LSQUARE_BRACKET";
	type_name[TokenType::RSQUARE_BRACKET] = "RSQUARE_BRACKET";
	type_name[TokenType::LBRACKET] = "LBRACKET";
	type_name[TokenType::RBRACKET] = "RBRACKET";
	type_name[TokenType::LBRACE] = "LBRACE";
	type_name[TokenType::RBRACE] = "RBRACE";
	type_name[TokenType::QUATATION] = "QUATATION";
	type_name[TokenType::DOUBLE_QUATATION] = "DOUBLE_QUATATION";

		//literals
	type_name[TokenType::INTEGER_LITERAL] = "INTEGER_LITERAL";
	type_name[TokenType::REAL_LITERAL] = "REAL_LOTERAL";
	type_name[TokenType::STRING_LITERAL] = "STRING_LITERAL";
	type_name[TokenType::IDENTIFIER] = "IDENTIFIER";
	type_name[TokenType::BOOLEAN_LITERAL] = "BOOLEAN_LITERAL";

		//special
	type_name[TokenType::END_OF_FILE] = "END_OF_FILE";
	
}