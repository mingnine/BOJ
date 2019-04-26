#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
	if (a.first > b.first)
		return false;
	else if (a.first == b.first)
	{
		return a.second < b.second;
	}
	else return true;
}

int main()
{
	int n;
	cin >> n;
	vector<pair<int,int>> v;
	
	for (int i = 0; i < n; i++)
	{
		int in;
		cin >> in;
		v.push_back({ in,i });
	}

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < n; i++)
	{
		v[i].first = v[i].second;
		v[i].second = i;
	}

	sort(v.begin(), v.end());

	for (auto value : v)
	{
		cout << value.second << " ";
	}
	return 0;
}