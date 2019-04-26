#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int arr[50][50];
int T;
int m, n, k;
int x, y;
int result;
queue<pair<int, int>> q;

bool possible(int tx, int ty)
{
	if (tx >= 0 && ty >= 0 && tx <= m - 1 && ty <= n - 1)
		return true;
	return false;
}

void f(int tx, int ty)
{
	if (arr[tx][ty] == 0)
		return;

	arr[tx][ty] = 0;

	if (possible(tx - 1, ty))
		f(tx - 1, ty);
	if (possible(tx + 1, ty))
		f(tx + 1, ty);
	if (possible(tx, ty - 1))
		f(tx, ty - 1);
	if (possible(tx, ty + 1))
		f(tx, ty + 1);
}

int main()
{
	cin >> T;

	while (T--)
	{
		memset(arr, 0, sizeof(int) * 50 * 50);
		result = 0;
		cin >> m >> n >> k;

		for (int i = 0; i < k; i++)
		{
			cin >> x >> y;
			arr[x][y] = 1;
			q.push(make_pair(x, y));
		}

		while (!q.empty())
		{
			int tx = q.front().first;
			int ty = q.front().second;
			q.pop();

			if (arr[tx][ty] == 0)
				continue;

			result++;
			f(tx, ty);
		}

		cout << result << endl;
	}

	return 0;
}
