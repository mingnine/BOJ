#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main()
{
	int t;

	cin >> t;

	while (t--)
	{
		int m, n;
		priority_queue<int> pq;
		queue<pair<int, int>> q;
		cin >> m >> n;

		for (int i = 0; i < m; i++)
		{
			int temp;
			cin >> temp;
			q.push(make_pair(temp, i));
			pq.push(temp);
		}


		int cnt = 0;
		while (q.size())
		{
			auto temp = q.front();
			q.pop();

			if (pq.top() == temp.first)
			{
				cnt++;
				pq.pop();
				if (n == temp.second)
					break;
			}
			q.push(temp);
		}
		cout << cnt << endl;
	}

	return 0;
}