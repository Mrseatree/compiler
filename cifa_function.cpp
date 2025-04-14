#include "DataStructure.h"

void get_nbc()
{
	while (c == ' ' || c == '\n')
	{
		/*
		if (c == ' ')
			col++;
		else if (c == '\n')
		{
			line++;
			col = 0;
		}*/
		get_char();
	}
	//restract();
}

void get_char()
{
	c = fgetc(fp);
	if (c == '\n')
	{
		line++;
		last_col = col;
		col = 0;
		return;
	}
	//printf("%c\n", c);
	col++;
}

void restract()
{
	ungetc(c, fp);
	if (c == '\n')
	{
		line--;
		col = last_col;
	}
	else
		col--;
	c = token.back();
	//token.pop_back();
}

int check(string word)
{
	//printf("%d\n", col);
	if (col == 0)cout << word << endl;
	string tmp_word;
	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] >= 'A' && word[i] <= 'Z')
		{
			tmp_word.push_back(tolower(word[i]));
		}
		else
			tmp_word.push_back(word[i]);
	}

	//cout << "TOLOWER: " << word << " -> " << tmp_word << endl;
	for (unordered_map<TokenType,string>::iterator it = type_name.begin(); 
		it !=type_name.end(); it++)
	{
		if (tmp_word == it->second)
		{
			token_stream.emplace_back(it->first, token, line, col);
			return 1;
		}
	}
	return 0;
}
