#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int n, m;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
vector<vector<int>> v;

int chk(int x, int y, int num)
{
	int size = 0;
	v[y][x] = num;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= m || ny >= n)
			continue;
		if (v[ny][nx] != 1)
			continue;
		size += chk(nx, ny, num);
	}
	return size + 1;
}

int main()
{
	cin >> n >> m;

	v.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
		}
	}

	int cnt = 0;	// 그림의 개수
	int maxsize = 0;
	int curnum = 2;	// 그림의 번호
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] == 1)
			{
				cnt++;
				maxsize = max(maxsize, chk(j, i, curnum++));
			}
		}
	}

	cout << cnt << "\n" << maxsize;

	return 0;
}