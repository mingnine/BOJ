#include <iostream>
#include <algorithm>
using namespace std;

int d[401][401];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int v, e;
	cin >> v >> e;

	for (int i = 0; i < e; i++)
	{
		int from, to, value;
		cin >> from >> to >> value;
		d[from - 1][to - 1] = value;
	}

	for (int k = 0; k < v; k++)
	{
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < v; j++)
			{
				if (d[i][j] == 0 && d[i][k] != 0 & d[k][j] != 0)
					d[i][j] = d[i][k] + d[k][j];
				else if (d[i][k] != 0 & d[k][j] != 0)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	int ret = 0x3f3f3f3f;
	for (int i = 0; i < v; i++)
	{
		if (d[i][i] == 0) continue;

		ret = min(ret, d[i][i]);
	}
	if (ret == 0x3f3f3f3f)
		cout << -1;
	else
		cout << ret;
	return 0;
}