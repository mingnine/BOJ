#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int chk[200] = { 0, };

	while (getline(cin, s))
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= 'a' && s[i] <= 'z')
			{
				chk[s[i] - 'a']++;
			}
		}
	}

	int max = 0;
	for (int i = 0; i <= 26; i++)
	{
		if (chk[i] > max)
			max = chk[i];
	}
	for (int i = 0; i <= 26; i++)
	{
		if (chk[i] == max)
		{
			char c = i + 'a';
			cout << c;
		}
	}

	return 0;
}