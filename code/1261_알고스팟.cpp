#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
#define D_MAX 101

int n, m;
int d[D_MAX][D_MAX];
bool visited[D_MAX][D_MAX];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
vector<vector<int>> v;
priority_queue < pair<int, pair<int, int>>> q;	// cost, x, y;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			d[i][j] = s[j] - '0';
		}
	}

	q.push({ 0,{0,0} });

	int ret = 0;
	while (!q.empty())
	{
		int cost = -q.top().first;
		int x = q.top().second.first;
		int y = q.top().second.second;
		q.pop();


		if (visited[y][x])
			continue;
		visited[y][x] = true;

		if (y == n - 1 && x == m - 1)
		{
			ret = cost;
			break;
		}


		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nc = cost;

			if (nx < 0 || ny < 0 || nx >= m || ny >= n)
				continue;
			if (visited[ny][nx])
				continue;

			if (d[ny][nx] == 1)
				nc++;

			q.push({ -nc, {nx, ny} });
		}
	}

	cout << ret;

	return 0;
}