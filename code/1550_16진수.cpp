#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int sum = 0;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		int temp = 0;
		if (s[s.length() - 1 - i] >= 'A')
		{
			temp = s[s.length() - 1 - i] - 'A' + 10;
		}
		else
		{
			temp = s[s.length() - 1 - i] - '0';
		}

		for (int j = 0; j < i; j++)
		{
			temp *= 16;
		}
		sum += temp;
	}
	cout << sum << endl;
	return 0;
}