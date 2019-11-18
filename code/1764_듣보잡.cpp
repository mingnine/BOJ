#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, cnt = 0;
	map<string, int> map;
	string s;
	cin >> n >> m;

	while (n--)
	{
		cin >> s;
		map[s]++;
	}
	while (m--)
	{
		cin >> s;
		map[s]++;
		if (map[s] > 1)
			cnt++;
	}

	cout << cnt << '\n';

	for (auto va : map)
	{
		if (va.second > 1)
			cout << va.first << "\n";
	}

	return 0;
}