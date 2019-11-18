#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int n, in;
priority_queue<int> maxq;
priority_queue<int, vector<int>, greater<int>> minq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;

	while (n--)
	{
		cin >> in;

		if (minq.empty() && maxq.empty())
			maxq.push(in);
		else if (minq.size() == maxq.size())
			maxq.push(in);
		else
			minq.push(in);

		if (!minq.empty() && !maxq.empty())
		{
			if (minq.top() < maxq.top())
			{
				int mintop = minq.top();
				int maxtop = maxq.top();
				minq.pop();
				maxq.pop();

				minq.push(maxtop);
				maxq.push(mintop);
			}
		}

		cout << maxq.top() << "\n";
	}

	return 0;
}