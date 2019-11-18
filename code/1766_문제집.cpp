#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> v;
vector<int> indegree;
priority_queue<int> q;

int main()
{
	cin >> n >> m;

	v.resize(n + 1);
	indegree.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}

	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(-i);
		}
	}

	while (!q.empty())
	{
		int nq = -q.top();
		q.pop();

		cout << nq << " ";

		for (int i = 0; i < v[nq].size(); i++)
		{
			indegree[v[nq][i]]--;
			if (indegree[v[nq][i]] == 0)
			{
				q.push(-v[nq][i]);
			}
		}
	}


	return 0;
}