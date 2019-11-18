#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int cnt = 0;
	int div = 10;
	int divn = 1;
	for (int i = 1; i <= n; i++)
	{
		while (i/div)
		{
			div *= 10;
			divn++;
		}
		cnt += divn;
	}
	cout << cnt << endl;
	return 0;
}