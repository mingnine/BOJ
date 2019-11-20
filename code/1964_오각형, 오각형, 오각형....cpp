#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	long long ret = 1;
	long long inc = 4;
	for (int i = 1; i <= n; i++)
	{
		ret += inc;
		ret %= 45678;
		inc += 3;
		inc %= 45678;
	}
	cout << ret;
	return 0;
}