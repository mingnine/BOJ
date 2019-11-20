#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct kruskal
{
	int from;
	int to;
	int val;
};


vector<kruskal> v;
int parent[1001];
bool chk;

bool comp(kruskal &a, kruskal &b)
{
	return a.val < b.val;
}

int find(int a)
{
	if (parent[a] == a)
		return a;
	return parent[a] = find(parent[a]);
}

void merge(int u, int v)
{
	chk = false;
	u = find(u);
	v = find(v);

	if (u == v)
		return;

	parent[u] = v;
	chk = true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, result = 0;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		parent[i] = i;


	for (int i = 0; i < m; i++)
	{
		kruskal ks;
		cin >> ks.from >> ks.to >> ks.val;
		v.push_back(ks);
	}
	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < m; i++)
	{
		merge(v[i].from, v[i].to);

		if (chk)
			result += v[i].val;
	}

	cout << result;

	return 0;
}