#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int line;
	int cnt = 0;
	char temp[1000003];
	cin.getline(temp, 1000003);
	line = strlen(temp);
	for (int i = 0; i < line; i++)
	{
		if (temp[i]==' ') cnt++;
	}
	if (temp[0] == ' ') cnt--;
	if (temp[line - 1] == ' ') cnt--;
	cout << cnt+1 << endl;

	return 0;
}