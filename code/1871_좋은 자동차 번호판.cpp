#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;

		int a = 0, b = 0;
		int temp = 676;
		for (int i = 0; i <= 2; i++)
		{
			a += (s[i] - 'A') * temp;
			temp /= 26;
		}
		temp = 1000;
		for (int i = 4; i <= 7; i++)
		{
			b += (s[i] - '0') * temp;
			temp /= 10;
		}

		if (abs(a - b) <= 100)
			cout << "nice\n";
		else
			cout << "not nice\n";
	}


	return 0;
}