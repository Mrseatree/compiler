#pragma once
#ifndef ERROR_H
#define ERROR_H
#include"DataStructure.h"

struct ErrorLog
{
	int id;
	int line;
	int col;

	ErrorLog(int i, int l, int c) :id(i), line(l), col(c) {};
};
extern int error_cnt;
extern struct vector<ErrorLog>error_logs;
extern unordered_map<int, string>error_info;

void output_logs();

#endif // !ERROR_H
