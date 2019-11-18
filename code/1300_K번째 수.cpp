#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k, ret;
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;

	int st = 1;
	int ed = k;
	while (st <= ed)
	{
		int mid = (st + ed) / 2;

		long long cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			cnt += min(n, mid / i);
		}

		if (cnt < k)
			st = mid + 1;
		else
		{
			ed = mid - 1;
			ret = mid;
		}
	}
	cout << ret;
	return 0;
}