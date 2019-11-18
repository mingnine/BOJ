#include <iostream>
using namespace std;

int n, m, s;
int d[401][401];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		d[from][to] = 1;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (d[i][k] && d[k][j])
				{
					d[i][j] = 1;
				}
			}
		}
	}


	cin >> s;
	for (int i = 0; i < s; i++)
	{
		int a, b;
		cin >> a >> b;

		if (d[a][b])
			cout << -1 << "\n";
		else if (d[b][a])
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}

	return 0;
}