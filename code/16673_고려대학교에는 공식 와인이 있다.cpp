#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int c, k, p;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> c >> k >> p;

	int ret = 0;
	for (int i = 1; i <= c; i++) {
		ret += k*i + p*i*i;
	}

	cout << ret;

	return 0;
}