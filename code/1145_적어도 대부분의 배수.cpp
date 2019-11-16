#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int p, int q)
{
	if (q > p) swap(p, q);
	if (q == 0) return p;
	return gcd(q, p%q);
}

int lcm(int a, int b)
{
	return a*b / gcd(a, b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a[5];
	for (int i = 0; i < 5; i++)
		cin >> a[i];

	int minn = 0x3f3f3f3f;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (i == j || i == k || j == k)
					continue;

				minn = min(minn, lcm(lcm(a[i], a[j]), a[k]));
			}
		}
	}

	cout << minn;
	return 0;
}
