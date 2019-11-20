#include <iostream>
#include <queue>
#include <functional>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	while (n--)
	{
		int input;
		cin >> input;

		if (input == 0)
		{
			if (pq.size() == 0)
			{
				cout << 0 << "\n";
			}
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
		{
			pq.push(input);
		}
	}

	return 0;
}