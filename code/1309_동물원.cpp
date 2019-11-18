#include <iostream>
using namespace std;

// 이전에 사자가 있던 경우
// 이전에 사자가 없던 경우

int d[100001];
int main()
{
	int n;
	cin >> n;
	d[0] = 1;
	d[1] = 3;
	d[2] = 7;
	for (int i = 3; i <= n; i++)
		d[i] = (d[i - 1] * 2 + d[i - 2]) % 9901;

	cout << d[n];
	return 0;
}