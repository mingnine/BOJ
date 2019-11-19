#include <iostream>
using namespace std;
#define DIV	15746

int d[1000001];

int main()
{
	int n;
	cin >> n;

	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		d[i] += d[i - 1];	// 1 붙일 경우
		d[i] += d[i - 2];	// 2 붙일 경우
		d[i] %= DIV;
	}

	cout << d[n];
	return 0;
}
