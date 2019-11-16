#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int m, n;
	queue<int> q;

	cin >> m >> n;

	for (int i = 1; i <= m; i++)
	{
		q.push(i);
	}

	cout << "<";
	while (!q.empty())
	{
		for (int i = 0; i < n - 1; i++)
		{
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
		cout << q.front();
		q.pop();
		if (!q.empty())
			cout << ", ";
	}
	cout << ">";

	return 0;
}