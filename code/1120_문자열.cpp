#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
	string s[2];
	cin >> s[0] >> s[1];



	int cmp = s[1].size() - s[0].size();
	int result = INT_MAX;
	for (int j = 0; j <= cmp; j++)
	{
		int cnt = 0;
		for (int i = 0; i < s[0].size(); i++)
		{
			if (s[0][i] != s[1][i + j])
				cnt++;
		}
		result = min(result, cnt);
	}

	cout << result;

	return 0;
}