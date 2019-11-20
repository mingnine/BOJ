#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n;
int result;
vector<pair<int, int>> v;

bool mysort(pair<int, int> v1, pair<int, int> v2)
{
	if (v1.second == v2.second)
		return v1.first < v2.first;
	else
		return v1.second < v2.second;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end(), mysort);


	int endtime = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i].first >= endtime)
		{
			endtime = v[i].second;
			result++;
		}
	}
	cout << result << endl;
	return 0;
}