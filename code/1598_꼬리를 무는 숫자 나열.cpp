#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b;

	if (a % 4 != 0)
	{
		c = a % 4;
		a = a / 4 + 1;
	}
	else
	{
		a = a / 4;
		c = 4;
	}

	if (b % 4 != 0)
	{
		d = b % 4;
		b = b / 4 + 1;
	}
	else
	{
		b = b / 4;
		d = 4;
	}

	cout << abs(b - a) + abs(c - d) << endl;
	return 0;
}