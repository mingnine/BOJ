#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f

int V, E, S;
vector<pair<int, int>> v[20002];

void dijkstra()
{
	vector<int> dist(V + 1, INF);	// 각 정점 코스트 기록용
	priority_queue<pair<int, int>> pq;	// 가장 비용이 싼 정점 찾기

	dist[S] = 0;
	pq.push({ 0, S });

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue;

		for (int i = 0; i < v[here].size(); i++)
		{
			int there = v[here][i].first;
			int nextcost = v[here][i].second + cost;

			if (nextcost < dist[there])
			{
				dist[there] = nextcost;
				pq.push({ -dist[there], there });
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E >> S;

	for (int i = 0; i < E; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;

		v[from].push_back({ to, cost });
	}

	dijkstra();
	return 0;
}