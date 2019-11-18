#include <iostream>
#include <utility>

using namespace std;

int m, n;
int arr[500][500] = { 0, };
int arr2[500][500] = { 0, };

bool possible(int x, int y, int orix, int oriy)
{
	if (x >= 0 && x < n && y >= 0 && y < m && arr[oriy][orix] > arr[y][x])
		return true;
	return false;
}

int dfs(int x, int y)
{
	if (x == n - 1 && y == m - 1)
	{
		return 1;
	}

	if (arr2[y][x] != -1)
	{
		return arr2[y][x];
	}

	int dirx[4] = { -1,1,0,0 };
	int diry[4] = { 0,0,1,-1 };
	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		if (possible(x + dirx[i], y + diry[i], x, y))
		{
			result += dfs(x + dirx[i], y + diry[i]);
		}
	}
	return arr2[y][x] = result;
}

int main()
{
	cin >> m >> n;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			arr2[i][j] = -1;
		}
	}

	dfs(0, 0);

	cout << arr2[0][0] << endl;

	return 0;
}