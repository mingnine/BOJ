#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int alp[26][2];
int main()
{
	string s[2];
	cin >> s[0] >> s[1];

	for (int i = 0; i < s[0].size(); i++)
	{
		alp[s[0][i] - 'a'][0]++;
	}
	for (int i = 0; i < s[1].size(); i++)
	{
		alp[s[1][i] - 'a'][1]++;
	}

	int cnt = 0;
	for (int i = 0; i < 26; i++)
	{
		if (alp[i][0] != alp[i][1])
			cnt += abs(alp[i][0] - alp[i][1]);
	}

	cout << cnt;
	return 0;
}