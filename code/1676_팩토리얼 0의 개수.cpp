#include <iostream>

using namespace std;

int main()
{
	int n, a = 1, b = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		a *= i;
		while (a % 10 == 0)
		{
			b++;
			a /= 10;
		}
		a %= 1000;
	}
	cout << b;
	return 0;
}