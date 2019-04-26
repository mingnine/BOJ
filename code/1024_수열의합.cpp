#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, l;
	vector<int> ans;
	cin >> n >> l;

	bool flag = false;
	for (int i = l; i <= 100; i++)
	{
		int mid = n / i;
		vector<int> v;
		for (int j = mid - i + 1; j <= mid + i - 1; j++)
		{
			if (j < 0) continue;
			v.push_back(j);

			if (v.size() > i)
				v.erase(v.begin());
			if (v.size() == i)
			{
				long long sum = 0;
				for (auto va : v)
					sum += va;
				if (sum == n) {
					flag = true;
					ans = v;
					break;
				}
			}
		}
		if (flag) break;
	}

	sort(ans.begin(), ans.end());
	if (flag)
		for (auto va : ans)
			cout << va << " ";
	else
		cout << -1;

	return 0;
}