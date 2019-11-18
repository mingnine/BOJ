#include <iostream>

using namespace std;

int arr[1001];
int main()
{
	int a, b, cnt, temp, result;
	cin >> a >> b;
	cnt = 1;
	temp = 0;
	result = 0;
	
	for (int i = 1; i <= b; i++)
	{
		arr[i] = cnt;
		temp++;
		if (temp == cnt)
		{
			cnt++;
			temp = 0;
		}
	}

	for (int i = a; i <= b; i++)
	{
		result += arr[i];
	}
	cout << result;
	return 0;
}