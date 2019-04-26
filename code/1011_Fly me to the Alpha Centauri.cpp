#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int a, b;
		int length;
		int result = 0;
		int i = 0;
		cin >> a >> b;

		length = b - a;

		if (length > 1)
		{
			for (i = 1;; i++)
			{
				if (length < i * 2)
				{
					break;
				}
				length -= i * 2;
				result += 2;
			}

			while (true)
			{
				if (length >= i)
				{
					length -= i;
					result++;
				}
				else
					i--;

				if (length == 0)
					break;
			}
			cout << result << endl;
		}
		else
			cout << 1 << endl;
	}
	return 0;
}