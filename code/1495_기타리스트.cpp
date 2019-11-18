#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s, m;
bool d[101][1001];
vector<int> v;

int main()
{
	cin >> n >> s >> m;

	for (int i = 0; i < n; i++)
	{
		int in;
		cin >> in;
		v.push_back(in);
	}

	if (s - v[0] >= 0 && s - v[0] <= m)
		d[0][s - v[0]] = true;
	if (s + v[0] >= 0 && s + v[0] <= m)
		d[0][s + v[0]] = true;

	for (int i = 1; i < n; i++)
	{
		for (int k = 0; k <= m; k++)
		{
			if (!d[i - 1][k]) continue;

			int minva = k - v[i];
			int maxva = k + v[i];
			if (minva >= 0 && minva <= m)
			{
				d[i][minva] = true;
			}
			if (maxva >= 0 && maxva <= m)
			{
				d[i][maxva] = true;
			}
		}
	}

	int ret = -1;
	for (int k = 0; k < 1001; k++)
	{
		if (d[n - 1][k])
			ret = max(ret, k);
	}
	cout << ret;
	return 0;
}