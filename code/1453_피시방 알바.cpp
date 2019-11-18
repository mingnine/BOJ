#include <iostream>
using namespace std;

int main()
{
	int n, result = 0;
	int pc[101] = { 0, };
	cin >> n;
	while (n--)
	{
		int i;
		cin >> i;
		if (!pc[i])
			pc[i] = 1;
		else
			result++;
	}
	cout << result;
	return 0;
}