#include <iostream>
using namespace std;
#define D_MAX 101

int n, m, ret;
char d[D_MAX][D_MAX];
int visited[D_MAX][D_MAX];

void f(int x, int y)
{
	for (int i = x; i < m; i++)
	{
		if (visited[y][i]) break;
		if (d[y][i] != '-') break;
		visited[y][i] = true;
	}
}

void f2(int x, int y)
{
	for (int i = y; i < n; i++)
	{
		if (visited[i][x]) break;
		if (d[i][x] != '|') break;
		visited[i][x] = true;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> d[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j]) continue;
			ret++;
			if (d[i][j] == '-')
			{
				f(j, i);
			}
			else
			{
				f2(j, i);
			}
		}
	}

	cout << ret;

	return 0;
}