#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int dp[100000][2];

int main()
{
	int T;
	int a, b;
	int result = 0;
	int max = 0;
	vector<int> vec;
	cin >> T;

	while (T--)
	{
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	dp[0][0] = vec[0];
	dp[0][1] = vec[0];
	
	for (int i = 1; i < vec.size(); i++)
	{
		dp[i][1] = (dp[i - 1][1] + vec[i]) < vec[i] ? vec[i] : (dp[i - 1][1] + vec[i]);
		if (dp[i][1] > dp[i - 1][0])
			dp[i][0] = dp[i][1];
		else
			dp[i][0] = dp[i - 1][0];
	}

	cout << dp[vec.size() - 1][0] << endl;
	return 0;
}
