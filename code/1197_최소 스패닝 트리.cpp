#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f

struct edge
{
	int from, to, cost;
};

int V, E, S;
vector<edge> adj;
vector<int> parent;

bool comp(const edge& a, const edge& b)
{
	return a.cost < b.cost;
}

int Find(int a)
{
	if (a == parent[a])
		return a;
	return parent[a] = Find(parent[a]);
}

bool Merge(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);

	if (pa == pb)	// 사이클이 존재
		return true;

	parent[pa] = pb;
	return false;
}

void Kruskal()
{
	// 부모를 자기 자신으로 초기화
	parent.resize(V + 1);
	for (int i = 1; i <= V; i++)
		parent[i] = i;

	// 비용이 작은 순으로 정렬
	sort(adj.begin(), adj.end(), comp);

	int ret = 0;
	for (int i = 0; i < E; i++)
	{
		int cost = adj[i].cost;
		int from = adj[i].from;
		int to = adj[i].to;

		if (!Merge(from, to))
			ret += cost;
	}

	cout << ret << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;

		adj.push_back({ from,to,cost });
	}

	Kruskal();
	return 0;
}