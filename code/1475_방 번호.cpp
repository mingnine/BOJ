#include <iostream>
#include <string>
using namespace std;

int main()
{
	string n;
	int cnt = 0;
	int index = 0;
	int arr[10] = { 0, };

	cin >> n;

	index = n.size() - 1;
	while (index >= 0)
	{
		int a = (n[index] - '0');
		index--;

		if (a == 9)
			a = 6;

		while (true)
		{
			if (arr[a] == cnt)
			{
				if (a == 6)
					a = 9;
				else
				{
					cnt++;
					arr[a]++;
					break;
				}
			}
			else if (arr[a] < cnt)
			{
				arr[a]++;
				break;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}