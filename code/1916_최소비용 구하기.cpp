#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f

vector<pair<int, int>> adj[1001];

vector<int> dijkstra(int src, int V, int E)
{
	vector<int> dist(V + 1, INF);
	priority_queue<pair<int, int>> pq;

	pq.push({ 0, src });

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue;

		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int nextDist = adj[here][i].second + cost;

			if (dist[there] > nextDist)
			{
				dist[there] = nextDist;
				pq.push({ -nextDist, there });
			}
		}
	}
	return dist;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}

	int st, ed;
	cin >> st >> ed;
	auto v = dijkstra(st, n, m);
	cout << v[ed];
	return 0;
}