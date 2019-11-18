#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define D_M	1009

int d[D_M][D_M];

int main()
{
	int n, m, x;
	cin >> n >> m >> x;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = c;
	}


	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j) continue;
				if (d[i][k] == 0 || d[k][j] == 0)
					continue;

				if (d[i][j] == 0)
					d[i][j] = d[i][k] + d[k][j];
				else
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i == x) continue;
		ret = max(ret, d[i][x] + d[x][i]);
	}
	cout << ret;
	return 0;
}