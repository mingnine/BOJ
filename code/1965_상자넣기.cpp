#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	vector<int> v, lis;

	cin >> n;
	while (n--)
	{
		int in;
		cin >> in;
		v.push_back(in);
	}

	for (int i = 0; i < v.size(); i++)
	{
		auto iter = lower_bound(lis.begin(), lis.end(), v[i]);
		if (iter == lis.end()) lis.push_back(v[i]);
		else *iter = v[i];
	}

	cout << lis.size();
	return 0;
}