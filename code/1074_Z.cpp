#include <iostream>
#include <cmath>
using namespace std;

int f(int n, int r, int c)
{
	int result = 0;
	int mid = pow(2, n) / 2;

	if (n == 1)
	{
		if (r == 0 && c == 0)
			return 0;
		else if (r == 0 && c == 1)
			return 1;
		else if (r == 1 && c == 0)
			return 2;
		else if (r == 1 && c == 1)
			return 3;
	}

	// 1
	if (r < mid && c < mid)
	{
		result = 0;
		result += f(n - 1, r, c);
	}

	// 2
	if (r < mid && c >= mid)
	{
		result = mid*mid;
		result += f(n - 1, r, c - mid);
	}

	// 3
	if (r >= mid && c < mid)
	{
		result = (mid*mid) * 2;
		result += f(n - 1, r - mid, c);
	}

	// 4
	if (r >= mid && c >= mid)
	{
		result = (mid*mid) * 3;
		result += f(n - 1, r - mid, c - mid);
	}
	return result;
}

int main()
{
	int n, r, c;
	cin >> n >> r >> c;
	cout << f(n, r, c);

	return 0;
}