#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, a, b;
vector<pair<int, int>> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--)
	{
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			v.push_back({ a,b });
		}
		sort(v.begin(), v.end());

		int cnt = 0;
		int comp = n + 1;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].second < comp)
			{
				cnt++;
				comp = v[i].second;
			}
		}
		cout << cnt << "\n";
		v.clear();
	}
	return 0;
}