#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INT_MAX	2e9

int n;
vector<int> v, ret;

int main()
{
	cin >> n;

	v.push_back(0);
	v.push_back(1);
	for (int i = 2;; i++)
	{
		if (v[i - 1] + i > n) break;
		v.push_back(v[i - 1] + i);
	}

	for (int i = 2; i < v.size(); i++)
	{
		v[i] += v[i - 1];
	}

	ret.resize(n+1);
	for (int i = 1; i <= n; i++)
	{
		ret[i] = INT_MAX;
		for (int j = 1; j < v.size(); j++)
		{
			if (i - v[j] >= 0)
			{
				ret[i] = min(ret[i], ret[i - v[j]] + 1);
			}
		}
	}

	cout << ret[n];
	return 0;
}