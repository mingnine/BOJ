#include <iostream>
#include <vector>
using namespace std;

vector<long long> v;
int main()
{
	for (int i = 1; i*i <= 10000; i++)
		v.push_back(i*i);

	int n, m, i, min;
	long long sum = 0;
	cin >> n >> m;

	for (i = 0; i < v.size() && v[i] < n; i++);
	min = v[i];

	for (i = i; i < v.size() && v[i] <= m; i++)
		sum += v[i];

	if (!sum)
		cout << -1 << endl;
	else
		cout << sum << "\n" << min;

	return 0;
}