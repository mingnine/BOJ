#include <iostream>
using namespace std;

int main()
{
	int x;
	int n = 64;
	int result = 0;
	cin >> x;

	while (x > 0)
	{
		if (x < n)
		{
			n = n / 2;
		}
		else
		{
			result++;
			x -= n;
		}
	}
	cout << result << endl;
}