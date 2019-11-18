#include <iostream>
#include <queue>
using namespace std;

int n, in, ret;
priority_queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> in;
		q.push(-in);
	}

	while (q.size() != 1)
	{
		int a = -q.top(); q.pop();
		int b = -q.top(); q.pop();
		int c = a + b;
		ret += c;
		q.push(-c);
	}
	cout << ret;
	return 0;
}