#include <iostream>
using namespace std;

int main()
{
	int n, a, b;
	cin >> n >> a >> b;

	int round = 1;
	while (true)
	{
		a = a / 2 + a % 2;
		b = b / 2 + b % 2;
		if (a == b) break;
		round++;
	}
	cout << round << endl;

	return 0;
}