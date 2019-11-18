#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

vector<int> vc[501];
int line[501]; 
int result[501]; 
int waiting[501]; 

int main()
{
	int n, m;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		int cur, prev;
		scanf("%d", &waiting[i]);
		cur = i;
		while (1)
		{
			scanf("%d", &prev);

			if (prev == -1)
				break;

			line[cur]++;
			vc[prev].push_back(cur);
		}
	}

	queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		if (line[i] == 0)
			q.push(i);

		result[i] += waiting[i];
	}

	for (int i = 0; i < n; i++)
	{
		int cur = q.front();
		q.pop();

		for (int j = 0; j < vc[cur].size(); j++)
		{
			int next = vc[cur][j];
			result[next] = max(result[next], result[cur] + waiting[next]);

			if (--line[next] == 0)
			{
				q.push(next);
			}
		}

	}


	for (int i = 1; i <= n; i++)
		printf("%d\n", result[i]);

	return 0;
}