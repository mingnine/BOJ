#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m, l;
	vector<int> v;
	cin >> n >> m >> l;

	v.resize(n+1);

	int cnt = 0;
	int cur = 1;
	bool flag = false;
	v[cur] = 1;
	while (true)
	{
		for (auto iter = v.begin(); iter != v.end(); iter++)
		{
			if (*iter == m)
			{
				flag = true;
				break;
			}
		}
		if (flag) break;

		if (v[cur] % 2 != 0)
		{
			cur += l;
			if(cur > n)
				cur -= n;
		}
		else
		{
			cur -= l;
			if (cur <= 0)
				cur += n;
		}
		v[cur]++;
		cnt++;
	}

	cout << cnt;

	return 0;
}