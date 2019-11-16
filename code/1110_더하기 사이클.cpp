#include <iostream>
using namespace std;


int main()
{
	int a, b, c, d, compare, cnt;
	cin >> a;

	b = a / 10;
	c = a % 10;
	d = c * 10 + (b + c) % 10;
	cnt = 1;

	while (1)
	{
		if (a == d)
			break;
		b = d / 10;
		c = d % 10;
		d = c * 10 + (b + c) % 10;
		cnt++;
	}
	cout << cnt;
	return 0;
}