#include <iostream>
#include <algorithm>
using namespace std;
#define D_MAX	51

int n, m, result;
int d[D_MAX][D_MAX];
int dx[] = { 1,0,1 };
int dy[] = { 0,1,1 };

bool f(int x, int y, int size)
{
	int curnum = d[y][x];


	bool chk[3] = { false, };
	for (int i = 0; i < 3; i++)
	{
		int nx = x + (dx[i] * size);
		int ny = y + (dy[i] * size);

		if (nx >= m || ny >= n) continue;

		if (d[ny][nx] == curnum)
		{
			chk[i] = true;
		}
	}

	if (chk[0] && chk[1] && chk[2])
		return true;
	else
		return false;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			d[i][j] = c - '0';
		}
	}


	int maxsize = min(n, m);

	for (int i = 0; i < maxsize; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (f(k, j, i))
				{
					result = max(result, (i + 1) * (i + 1));
				}
			}
		}
	}
	cout << result;
	return 0;
}