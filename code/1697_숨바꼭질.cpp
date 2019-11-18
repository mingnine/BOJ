#include <iostream>
#include <queue>
#include <cstring>
#include <utility>

using namespace std;


int main()
{
	int N, K;
	int visited[100001];
	queue<pair<int, int>> q;
	cin >> N >> K;

	q.push(make_pair(N, 0));
	visited[N] = 1;
	memset(visited, 0, sizeof(int) * 100001);

	while (true)
	{
		if (q.front().first == K)
		{
			cout << q.front().second << endl;
			break;
		}
		if (q.front().first * 2 < 100001 && visited[q.front().first * 2] == 0)
		{
			visited[q.front().first * 2] = 1;
			q.push(make_pair(q.front().first * 2, q.front().second + 1));
		}
		if (q.front().first > 0 && visited[q.front().first - 1] == 0)
		{
			visited[q.front().first - 1] = 1;
			q.push(make_pair(q.front().first - 1, q.front().second + 1));
		}
		if (q.front().first + 1 < 100001 && visited[q.front().first + 1] == 0)
		{
			visited[q.front().first + 1] = 1;
			q.push(make_pair(q.front().first + 1, q.front().second + 1));
		}
		q.pop();
	}

	return 0;
}
