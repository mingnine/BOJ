#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<pair<int,int>> v;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int in;
		cin >> in;
		v.push_back({ in,i });
	}
	sort(v.begin(), v.end());

	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i].second - i > ret)
			ret = v[i].second - i;
	}
	cout << ret + 1;
	return 0;
}