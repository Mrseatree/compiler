#include "Error.h"
#include "DataStructure.h"
void add_logs(int id, int line, int col)
{
	error_logs.emplace_back(id, line, col);
	error_cnt++;
}

void output_logs()
{
	printf("ERROR:%d\n", error_cnt);
	for (auto log : error_logs)
	{
		printf("ERROR %d: LINE %d COL %d:", log.id, log.line, log.col);
		cout<<error_info[log.id]<<endl;
	}
}