#include <iostream>

using namespace std;

int main()
{
	int T;
	int result = 0;
	int index;
	cin >> T;

	for (int i = 1;; i++)
	{
		result += i;
		if (result >= T)
		{
			result -= i;
			index = i;
			break;
		}
	}

	if(index % 2 == 0)
		cout << 1 + (T - result - 1) << "/" <<index- (T - result - 1) << endl;
	else
		cout << index - (T - result - 1) << "/" << 1 + (T - result - 1) << endl;

	return 0;
}
