#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int n, cluster;
	vector<int> v;

	cin >> n;

	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	cin >> cluster;

	long long cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i] == 0) continue;
		if (v[i] > cluster)
		{
			cnt += v[i] / cluster;
			if (v[i] % cluster > 0)
				cnt++;
		}
		else
			cnt++;
	}

	cout << cluster * cnt;

	return 0;
}