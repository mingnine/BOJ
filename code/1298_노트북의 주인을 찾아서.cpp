#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> adjust;
vector<int> notebook;
vector<bool> visited;

bool dfs(int here)
{
	if (visited[here]) return false;
	visited[here] = true;

	for (int b = 0; b < adjust[here].size(); b++)
	{
		int there = adjust[here][b];
		if (!notebook[there] || dfs(notebook[there]))
		{
			notebook[there] = here;
			return true;
		}
	}

	return false;
}

int bipartite()
{
	int size = 0;

	for (int i = 1; i <= n; i++)
	{
		visited = vector<bool>(n + 1);
		if (dfs(i))
			size++;
	}

	return size;
}

int main()
{
	cin >> n >> m;
	adjust = vector<vector<int>>(n + 1);
	notebook = vector<int>(n + 1, 0);

	for (int i = 0; i < m; i++)
	{
		int c, d;
		cin >> c >> d;
		adjust[c].push_back(d);
	}
	cout << bipartite() << endl;
	return 0;
}