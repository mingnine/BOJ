#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;

	long long sum = 0;
	int i = 1;
	for (;sum <= n; i++) sum += i;

	cout << i - 2;
	return 0;
}