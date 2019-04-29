#include <iostream>

using namespace std;

int main()
{
	int num;
	int result = 0;
	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		if (i >= 1 && i <= 99)
		{
			result++;
		}
		else if (i >= 100 && i <= 999)
		{
			int a = i / 100;
			int b = (i % 100) / 10;
			int c = i % 10;

			if (b - a == c - b)
				result++;
		}
	}
	cout << result << endl;

	return 0;
}
