#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	int n;
	vector<int> vec;
	cin >> n;

	while (n > 0)
	{
		vec.push_back(n % 10);
		n = n / 10;
	}
	sort(vec.begin(), vec.end(), greater<int>());

	for (int a : vec)
		cout << a;


	return 0;
}