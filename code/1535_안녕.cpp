#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, ret;
vector<int> L, J, dp;

int main()
{
	cin >> t;
	L.resize(t);
	J.resize(t);
	dp.resize(101);
	for (int i = 0; i < t; i++)
		cin >> L[i];
	for (int i = 0; i < t; i++)
		cin >> J[i];

	for (int i = 0; i < t; i++)
	{
		for (int j = 100; j >= 0; j--)
		{
			if (j - L[i] <= 0) continue;
			dp[j] = max(dp[j], dp[j - L[i]] + J[i]);
			ret = max(ret, dp[j]);
		}
	}
	cout << ret;

	return 0;
}