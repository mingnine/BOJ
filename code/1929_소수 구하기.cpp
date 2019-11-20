#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
bool d[1000001];
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 2; i <= m; i++)
	{
		if (!d[i])
		{
			v.push_back(i);

			for (int j = i + i; j <= m; j += i)
				d[j] = true;
		}
	}

	for (auto va : v)
	{
		if (va >= n && va <= m)
			cout << va << "\n";
	}
	return 0;
}