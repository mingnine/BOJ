#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define A_MAX	10001

vector<pair<int,int>> v[A_MAX];
vector<bool> visited;


void dfs(int idx, int value, int *maxresult, int *idxresult)
{
	if (v[idx].size() == 1 && visited[v[idx][0].first])
	{
		if ((*maxresult) < value)
		{
			(*maxresult) = value;
			(*idxresult) = idx;
		}
		return;
	}
	for (int i = 0; i < v[idx].size(); i++)
	{
		int nto = v[idx][i].first;
		int nvalue = v[idx][i].second;

		if (!visited[nto])
		{
			visited[nto] = true;
			dfs(nto, value + nvalue, maxresult, idxresult);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, root = -1;
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int from, to, value;
		cin >> from >> to >> value;

		if (root == -1) root = from;

		v[from].push_back({ to, value });
		v[to].push_back({ from, value });
	}

	int mr = 0;
	int midx = 0;
	visited.resize(A_MAX, 0);
	visited[root] = true;
	dfs(root, 0, &mr, &midx);
	visited.clear();


	root = midx;
	mr = 0;
	midx = 0;
	visited.resize(A_MAX, 0);
	visited[root] = true;
	dfs(root, 0, &mr, &midx);
	visited.clear();

	cout << mr << "\n";

	return 0;
}