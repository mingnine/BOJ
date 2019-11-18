#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int n, numcnt = 9;
map<char, int> lis;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		reverse(s.begin(), s.end());

		int k = 1;
		for (int j = 0; j < s.size(); j++)
		{
			lis[s[j]] += k;
			k *= 10;
		}
	}

	int ret = 0;
	while (!lis.empty())
	{
		int value = 0;
		char key;

		for (auto va : lis)
		{
			if (value < va.second)
			{
				value = va.second;
				key = va.first;
			}
		}
		ret += value * numcnt--;
		lis.erase(key);
	}
	cout << ret;

	return 0;
}