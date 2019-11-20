#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	vector<int> v;

	cin >> n >> m;

	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end());

	int st = 0, ed = v.size() - 1, cnt = 0;
	while (st < ed)
	{
		if (v[st] + v[ed] < m)
			st++;
		else if (v[st] + v[ed] > m)
			ed--;
		else
		{
			cnt++;
			st++;
			ed--;
		}
	}

	cout << cnt;
	return 0;
}