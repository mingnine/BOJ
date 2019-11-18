#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	map<string, int> map;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		map[s]++;
	}

	string ret;
	int retcnt = -1;
	for (auto iter = map.begin(); iter != map.end(); iter++)
	{
		if (retcnt < (*iter).second)
		{
			retcnt = (*iter).second;
			ret = (*iter).first;
		}
	}

	cout << ret;
	return 0;
}