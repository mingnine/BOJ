#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
	int n, m;
	int result = 0;
	deque<int> d;
	deque<int> d2;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		d2.push_back(temp);
	}
	for (int i = 1; i <= n; i++)
	{
		d.push_back(i);
	}

	while (!d2.empty())
	{
		int cnt = 0;
		for (int i = 0; i < d.size(); i++)
		{
			cnt = i;
			if (d2.front() == d[i])
				break;
		}

		// 왼쪽 이동
		if (cnt > d.size() / 2)
		{
			while (true)
			{
				if (d2.front() == d.front())
				{
					d2.pop_front();
					d.pop_front();
					break;
				}
				else
				{
					int temp = d.back();
					d.pop_back();
					d.push_front(temp);
					result++;
				}
			}
		}
		// 우측 이동
		else
		{
			while (true)
			{
				if (d2.front() == d.front())
				{
					d2.pop_front();
					d.pop_front();
					break;
				}
				else
				{
					int temp = d.front();
					d.pop_front();
					d.push_back(temp);
					result++;
				}
			}
		}
	}

	cout << result << endl;

	return 0;
}