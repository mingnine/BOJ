#include <iostream>
using namespace std;
#define INF	0x3f3f3f3f
int d[102];

int main()
{
	int n, m;
	int maxa = INF, maxb = INF;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (maxa > a)
			maxa = a;
		if (maxb > b)
			maxb = b;
	}

	d[1] = maxb < maxa ? maxb : maxa;
	for (int i = 2; i <= n; i++)
	{
		int tempa = d[i - 1] + maxb;

		int tempb = INF;
		for (int k = 1; k <= 6; k++)
		{
			if (i >= k)
				if (tempb > d[i - k] + maxa)
				{
					tempb = d[i - k] + maxa;
				}
		}
		d[i] = tempa > tempb ? tempb : tempa;
	}

	cout << d[n] << endl;

	return 0;
}