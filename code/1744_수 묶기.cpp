#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, ret;
priority_queue<int> q;	// 양수
priority_queue<int> mq;	// 음수

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int in;
		cin >> in;
		if (in <= 0)
			mq.push(-in);
		else if (in > 1)
			q.push(in);
		else
			ret += in;
	}

	int pre = -1;
	while (!q.empty())
	{
		int v = q.top();
		q.pop();

		if (pre == -1)
		{
			pre = v;
			continue;
		}

		ret += pre * v;
		pre = -1;
	}
	if (pre != -1)
		ret += pre;

	pre = -1;
	while (!mq.empty())
	{
		int v = mq.top();
		mq.pop();

		if (pre == -1)
		{
			pre = v;
			continue;
		}
		ret += pre * v;
		pre = -1;
	}
	if (pre != -1)
		ret += -pre;


	cout << ret;

	return 0;
}