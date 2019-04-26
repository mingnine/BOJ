#include <iostream>
using namespace std;

bool d[1000001];

int main()
{
	long long n, m;
	cin >> n >> m;

	for (long long i = 2; i*i <= m; i++)
	{
		long long temp = n / (i*i);
		while (temp*i*i < n) temp++;

		while (temp*i*i <= m)
		{
			d[temp*i*i - n] = 1;
			temp++;
		}
	}


	int cnt = 0;
	for (int i = 0; i <= m - n; i++)
	{
		if (!d[i])
			cnt++;
	}

	cout << cnt;

	return 0;
}