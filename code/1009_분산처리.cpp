#include <iostream>

using namespace std;

int main()
{
	int N;
	long long a, b, c;

	cin >> N;

	for (int j = 0; j < N; j++)
	{
		cin >> a >> b;
		c = a;
		for (int i = 0; i < b - 1; i++)
		{
			a = a * c % 10;
		}

		if (a == 0)
			cout << 10 << endl;
		else
			cout << a << endl;
	}
	return 0;
}