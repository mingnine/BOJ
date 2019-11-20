#include <iostream>
using namespace std;

bool prime(int n)
{
	if (n < 2) return false;
	for (int i = 2; i*i <= n; i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int N, a, cnt = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a;
		if (prime(a))
			cnt++;
	}
	cout << cnt << endl;

	return 0;
}