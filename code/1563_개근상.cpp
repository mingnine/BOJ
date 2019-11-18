#include <iostream>
using namespace std;
#define DIV	1000000

int d[1001][2][3];

int main()
{
	int n;
	cin >> n;

	d[1][0][0] = 1;
	d[1][1][0] = 1;
	d[1][0][1] = 1;

	for (int i = 2; i <= n; i++)
	{
		d[i][0][0] += d[i - 1][0][0] + d[i - 1][0][1] + d[i - 1][0][2];
		d[i][0][0] %= DIV;
		d[i][0][1] += d[i - 1][0][0];
		d[i][0][1] %= DIV;
		d[i][0][2] += d[i - 1][0][1];
		d[i][0][2] %= DIV;

		d[i][1][0] += d[i - 1][0][0] + d[i - 1][0][1] + d[i - 1][0][2] + d[i - 1][1][0] + d[i - 1][1][1] + d[i - 1][1][2];
		d[i][1][0] %= DIV;
		d[i][1][1] += d[i - 1][1][0];
		d[i][1][1] %= DIV;
		d[i][1][2] += d[i - 1][1][1];
		d[i][1][2] %= DIV;
	}
	long long ret = 0;
	ret += d[n][0][0];
	ret %= DIV;
	ret += d[n][1][0];
	ret %= DIV;
	ret += d[n][0][1];
	ret %= DIV;
	ret += d[n][0][2];
	ret %= DIV;
	ret += d[n][1][1];
	ret %= DIV;
	ret += d[n][1][2];
	ret %= DIV;
	cout << ret;

	return 0;
}