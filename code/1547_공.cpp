#include <iostream>
using namespace std;

int main()
{
	int n, arr[3] = {1,2,3};
	cin >> n;
	while (n--)
	{
		int a, b, t1, t2;
		cin >> a >> b;
		for (int i = 0; i < 3; i++)
		{
			if (arr[i] == a)
			{
				t1 = i;
			}
			else if (arr[i] == b)
			{
				t2 = i;
			}
		}
		arr[t1] = b;
		arr[t2] = a;
	}
	cout << arr[0] << endl;
	return 0;
}