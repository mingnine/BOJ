#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;

	if (n % 2 == 0 || n % 5 == 0) cout << -1;
	else
	{
		long long a = 1;
		int cnt = 1;
		while (a%n)
		{
			a = a * 10 + 1;
			a %= n;
			cnt++;
		}
		cout << cnt;
	}

	return 0;
}