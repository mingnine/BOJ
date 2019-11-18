#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 1; n > 0; i++, cnt++)
	{
		if (n - i < 0)
			i = 1;
		n -= i;
	}
	cout << cnt;
	return 0;
}