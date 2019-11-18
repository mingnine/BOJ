#include <iostream>

using namespace std;

int main()
{
	long long a, b, c, result = 1LL;
	cin >> a >> b >> c;

	while (b > 0)
	{
		if (b % 2 == 1)
		{
			result *= a;
			result %= c;
		}
		a *= (a%c);
		a %= c;
		b /= 2;
	}

	cout << result % c << endl;
	return 0;
}