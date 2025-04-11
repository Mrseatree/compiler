#include"DataStructure.h"
FILE* fp = fopen("test.psc", "r");
int line = 0, col = 0;
char c;
string token;
vector<TokenType>token_stream;

void get_nbc()
{
	while (c == ' ' || c == '\n')
	{
		if (c == ' ')
			col++;
		else if (c == '\n')
		{
			line++;
			col = 0;
		}
	}
}

void get_char()
{
	c = fgetc(fp);
	if (c == '\n')
	{
		line++;
		col = 0;
		return;
	}
	col++;
//	if (c >= 'A' && c <= 'Z')
// 		tolower(c);
}

void restract()
{
	ungetc(c, fp);
	c = token.back();
	token.pop_back();
	col--;
}

int check(string word)
{
	string tmp_word;
	for (int i=0;i<word.size();i++)
	{
		char c = word[i];
		if (c >= 'A' && c <= 'Z')
		{
			tolower(c);
			tmp_word.push_back(c);
		}
	}
	for (int i=0;i<keywords.size();i++)
	{
		if (tmp_word == keywords[i])
		{
			token_stream.emplace_back(types[i], token, line, col);
			return 1;
		}
	}
	return 0;
}

vector<TokenType> lex()
{
	int state = 0;
	init_keywords();

	do
	{
		switch (state)
		{
		case 0:
			token.clear();
			get_char();
			get_nbc();
			switch (c)
			{
			case ':':state = 1; break;
			case '>':state = 2; break;
			case '<':state = 3; break;
			case '+':token.push_back(c); token_stream.emplace_back(TokenType::PLUS, token, line, col); break;
			case '-':token.push_back(c); token_stream.emplace_back(TokenType::MINUS, token, line, col); break;
			case '*':token.push_back(c); token_stream.emplace_back(TokenType::MULTIPLY, token, line, col); break;
			//case '/':token.push_back(c); token_stream.emplace_back(TokenType::DIVIDE, token, line, col); break;
			case '=':token.push_back(c); token_stream.emplace_back(TokenType::EQUAL, token, line, col); break;
			case 'M':
			case 'm':state = 4; break;
			case 'D':
			case 'd':state = 5; break;
			case 'A':
			case 'a':state = 6; break;
			case 'O':
			case 'o':state = 7; break;
			case 'S':
			case 's':state = 8; break;
			case 'N':
			case 'n':state = 9; break;
			case 'I':
			case 'i':state = 10; break;

			case ',':token.push_back(c); token_stream.emplace_back(TokenType::COMMA, token, line, col); break;
			case ';':token.push_back(c); token_stream.emplace_back(TokenType::SEMICOLON, token, line, col); break;
			//case '(':token.push_back(c); token_stream.emplace_back(TokenType::LBRACKET, token, line, col); break;
			case ')':token.push_back(c); token_stream.emplace_back(TokenType::RBRACKET, token, line, col); break;
			case '[':token.push_back(c); token_stream.emplace_back(TokenType::LSQUARE_BRACKET, token, line, col); break;
			case ']':token.push_back(c); token_stream.emplace_back(TokenType::LSQUARE_BRACKET, token, line, col); break;
			//case '{':token.push_back(c); token_stream.emplace_back(TokenType::LBRACE, token, line, col); break;
			case '}':token.push_back(c); token_stream.emplace_back(TokenType::RBRACE, token, line, col); break;
			case '\'':token.push_back(c); token_stream.emplace_back(TokenType::QUATATION, token, line, col); break;
			case '\"':token.push_back(c); token_stream.emplace_back(TokenType::DOUBLE_QUATATION, token, line, col); break;
			case '.':state = 51; break;

			case '{':state=301; break;
			case '(':state = 302; break;
			case '/':state = 305; break;

			case 'B':case 'b':case 'C':case 'c':case 'E':case 'e':case 'F':case 'f':
			case 'G':case 'g':case 'H':case 'h':case 'J':case 'j':case 'K':case 'k':
			case 'L':case 'l':case 'P':case 'p':case 'Q':case 'q':case 'R':case 'r':
			case 'T':case 't':case 'U':case 'u':case 'V':case 'v':case 'W':case 'w':
			case 'X':case 'x':case 'Y':case 'y':case 'Z':case 'z':
				state = 101; break;
			}
		case 1:
			token.push_back(c);
			get_char();
			switch (c)
			{
			case '=':token.push_back(c); state = 0; token_stream.emplace_back(TokenType::ASSIGN,token,line,col); break;
			default:restract(); state = 0; token_stream.emplace_back(TokenType::COLON,token,line,col); break;
			}
			break;
		case 2:
			token.push_back(c);
			get_char();
			switch (c)
			{
			case '=':token.push_back(c); state = 0; token_stream.emplace_back(TokenType::GREATER_EQUAL, token, line, col); break;
			default:restract(); state = 0; token_stream.emplace_back(TokenType::GREATER, token, line, col); break;
			}
			break;
		case 3:
			token.push_back(c);
			get_char();
			switch (c)
			{
			case '=':token.push_back(c); state = 0; token_stream.emplace_back(TokenType::LESS_EQUAL, token, line, col); break;
			case '>':token.push_back(c); state = 0; token_stream.emplace_back(TokenType::NOT_EQUAL, token, line, col); break;
			default:restract(); state = 0; token_stream.emplace_back(TokenType::LESS, token, line, col); break;
			}
			break;
		case 4:
			token.push_back(c);
			get_char();
			switch (c)
			{
			case 'O':
			case 'o':state = 11; break;
			default:restract(); state = 101; break;
			}
			break;
		case 5:
			token.push_back(c);
			get_char();
			switch (c)
			{
			case 'I':
			case 'i':state = 13; break;
			default:restract(); state = 101; break;
			}
			break;
		case 6:
			token.push_back(c);
			get_char();
			switch (c)
			{
			case 'N':
			case 'n':state = 16; break;
			default:restract(); state = 101; break;
			}
			break;
		case 7:
			token.push_back(c);
			get_char();
			switch (c)
			{
			case 'R':
			case 'r':state = 18; break;
			default:restract(); state = 101; break;
			}
			break;
		case 8:
			token.push_back(c);
			get_char();
			switch (c)
			{
			case 'H':
			case 'h':state = 19; break;
			default:restract(); state = 101; break;
			}
			break;
		case 9:
			token.push_back(c);
			get_char();
			switch (c)
			{
			case 'O':
			case 'o':state = 22; break;
			default:restract(); state = 101; break;
			}
			break;
		case 10:
			token.push_back(c);
			get_char();
			switch (c)
			{
			case 'N':
			case 'n':state = 24; break;
			default:restract(); state = 101; break;
			}
			break;
		case 11:
			token.push_back(c);
			get_char();
			switch (c)
			{
			case 'D':
			case 'd':state = 12; break;
			default:restract(); state = 101; break;
			}
			break;
		case 12:
			token.push_back(c);
			get_char();
			switch (c)
			{
			case ' ':state = 0; token_stream.emplace_back(TokenType::MOD, token, line, col); break;
			default:restract(); state = 101; break;
			}
			break;
		case 13:
			token.push_back(c);
			get_char();
			switch (c)
			{
			case 'V':
			case 'v':state = 15; break;
			default:restract(); state = 101; break;
			}
			break;
		case 14:
			token.push_back(c);
			get_char();
			switch (c)
			{
			case 'D':
			case 'd':state = 15; break;
			default:restract(); state = 101; break;
			}
			break;
		case 15:
			token.push_back(c);
			get_char();
			switch (c)
			{
			case ' ': state = 0; token_stream.emplace_back(TokenType::DIV, token, line, col); break;
			default:restract(); state = 101; break;
			}
			break;
		case 16:
			token.push_back(c);
			get_char();
			switch (c)
			{
			case 'D':
			case 'd':state = 17; break;
			default:restract(); state = 101; break;
			}
			break;
		case 17:
			token.push_back(c);
			get_char();
			switch (c)
			{
			case ' ':state = 0; token_stream.emplace_back(TokenType::AND, token, line, col); break;
			default:restract(); state = 101; break;
			}
			break;
		case 18:
			token.push_back(c);
			get_char();
			switch (c)
			{
			case ' ':state = 0; token_stream.emplace_back(TokenType::OR, token, line, col); break;
			default:restract(); state = 101; break;
			}
			break;
		case 19:
			token.push_back(c);
			get_char();
			switch (c)
			{
			case 'L':
			case 'l':state = 20; break;
			case 'R':
			case 'r':state = 21; break;
			default:restract(); state = 101; break;
			}
			break;
		case 20:
			token.push_back(c);
			get_char();
			switch(c)
			{
			case ' ':state = 0; token_stream.emplace_back(TokenType::LEFT_SHIFT, token, line, col); break;
			default:restract(); state = 101; break;
			}
			break;
		case 21:
			token.push_back(c);
			get_char();
			switch (c)
			{
			case ' ':state = 0; token_stream.emplace_back(TokenType::RIGHT_SHIFT, token, line, col); break;
			default:restract(); state = 101; break;
			}
			break;
		case 22:
			token.push_back(c);
			get_char();
			switch (c)
			{
			case 'T':
			case 't':state = 23; break;
			default:restract(); state = 101; break;
			}
			break;
		case 23:
			token.push_back(c);
			get_char();
			switch (c)
			{
			case ' ':state = 0; token_stream.emplace_back(TokenType::NOT, token, line, col); break;
			default:restract(); state = 101; break;
			}
			break;
		case 24:
			token.push_back(c);
			get_char();
			switch (c)
			{
			case ' ':state = 0; token_stream.emplace_back(TokenType::IN, token, line, col); break;
			default:restract(); state = 101; break;
			}
			break;
		case 51:
			token.push_back(c);
			get_char();
			switch (c)
			{
			case '.':token.push_back(c); state = 0; token_stream.emplace_back(TokenType::DOTDOT, token, line, col); break;
			default:restract(); state = 0; token_stream.emplace_back(TokenType::DOT, token, line, col); break;
			}
			break;

		case 101:
			token.push_back(c);
			get_char();
			if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
			{
				state = 101;
				break;
			}
			else if (c == ' ')
			{
				state = 0;
				int iskey = check(token);
				if (iskey)break;
				else
				{
					//插入符号表
				}
			}


		//大括号多行注释
		case 301:
			token.push_back(c);
			get_char();
			while (c != '}'&&c!=EOF)
			{
				get_char();
			}
			break;
		//小括号星号多行注释
		case 302:
			token.push_back(c);
			get_char();
			if (c == '*')
			{
				state = 303; 
			}
			else
			{
				restract();
				state = 0;
				token_stream.emplace_back(TokenType::LBRACKET, token, line, col);
			}
			break;
		case 303:
			get_char();
			while (c != '*'&&c!=EOF)
			{
				get_char();
			}
			if (c == '*')
			{
				state = 304;
			}
			break;
		case 304:
			get_char();
			if (c == ')')
			{
				state = 0;
			}
			else
			{
				state = 303;
			}
			break;
		//单行注释
		case 305:
			token.push_back(c);
			get_char();
			if (c == '/')
			{
				state = 306;
			}
			else
			{
				state = 0;
				token_stream.emplace_back(TokenType::DIVIDE, token, line, col);
			}
			break;
		case 306:
			while (c != '\n' && c != EOF)
			{
				get_char();
			}
			break;
		}
	} while (c != EOF);
	token_stream.emplace_back(TokenType::END_OF_FILE, "", line, col);
	return token_stream;
}