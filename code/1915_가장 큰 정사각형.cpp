#include <iostream>
#include <algorithm>
using namespace std;
#define D_MAX	1001

int n, m, ret;
int d[D_MAX][D_MAX];

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%1d", &d[i][j]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if(d[i][j] == 1)
			{
				d[i][j] = min(min(d[i - 1][j], d[i][j - 1]), d[i - 1][j - 1]) + 1;
				ret = max(ret, d[i][j]);
			}
		}
	}

	cout << ret * ret;
	return 0;
}