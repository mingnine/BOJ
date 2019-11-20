#include <iostream>
#include <algorithm>
using namespace std;
#define D_MAX	501

int n;
int d[D_MAX][D_MAX];
int visited[D_MAX][D_MAX];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int f(int x, int y, int day)
{
	if (visited[y][x] != 0)
	{
		return visited[y][x] + day;
	}

	day++;

	int ret = day;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (d[ny][nx] <= d[y][x]) continue;

		int fret = f(nx, ny, day);
		ret = max(ret, fret);
		visited[ny][nx] = max(visited[ny][nx], fret - day);
	}
	return ret;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> d[i][j];


	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visited[i][j] = f(j, i, 0);
			ret = max(ret, visited[i][j]);
		}
	}

	cout << ret;
	return 0;
}
}