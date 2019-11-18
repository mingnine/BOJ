#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s;
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		v[i] += v[i - 1];
	}

	int st = 0;
	int ed = v.size() - 1;
	int dist = ed - st;

	while (st < v.size())
	{
		if (v[ed] - v[st] >= s)
		{
			dist = ed - st;
			ed--;
		}
		else
		{
			st++;
			ed = st + dist - 1;

			if (ed >= v.size())
				break;
		}
	}
	if (v[v.size() - 1] - v[0] < s)
		cout << 0;
	else
		cout << dist;
	return 0;
}