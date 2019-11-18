#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int N, M, V;
int line[1003][1003] = { 0, };
bool visit[1003] = { false, };


void DFS(int a)
{
	visit[a] = true;

	cout << a << " ";

	for (int i = 1; i <= N; i++)
	{
		if (line[a][i] && !visit[i])
		{
			DFS(i);
		}
	}
}

void BFS(int a)
{
	queue<int> Q;
	Q.push(a);
	visit[a] = true;

	while (!Q.empty())
	{
		int temp = Q.front();
		Q.pop();
		cout << temp << " ";
		for (int i = 1; i <= N; i++)
		{
			if(line[temp][i] && !visit[i])
			{
				Q.push(i);
				visit[i] = true;
			}
		}
	}
}

int main()
{
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		line[a][b] = 1;
		line[b][a] = 1;
	}

	DFS(V);
	cout << endl;
	memset(visit, false, 1003);
	BFS(V);

	return 0;
}

