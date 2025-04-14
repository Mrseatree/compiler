#include "DataStructure.h"
#include "Error.h"

int error_cnt;
struct vector<ErrorLog>error_logs;
unordered_map<int, string>error_info;

int main()
{
	vector<Token> stream=lex();
	for (auto t : stream)
	{
		printf("LINE %d, COL %d:", t.line, t.column);
		int index = std::distance(types.begin(),
			std::find(types.begin(), types.end(), t.type));
		//printf("%d\n", index); getchar();
		cout << t.value << " type: " << type_name[t.type] << endl;
	}
	return 0;
}