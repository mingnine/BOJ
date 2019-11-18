#include <iostream>
#include <algorithm>
using namespace std;


void f(int target, int num, int *ret)
{
	if (target < num) return;
	if (target >= num)
	{
		(*ret) = max((*ret), num);
	}

	num *= 10;
	f(target, num + 4, ret);
	f(target, num + 7, ret);
}

int main()
{
	int n, ret = 0;
	cin >> n;
	f(n, 0, &ret);

	cout << ret;
	return 0;
}