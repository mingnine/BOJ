#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<int> v;

int main()
{
	cin >> n >> c;
	while (n--)
	{
		int in;
		cin >> in;
		v.push_back(in);
	}

	int cnt = 0;
	for (int i = 1; i <= c; i++)
	{
		for (auto va : v)
		{
			if (i % va == 0)
			{
				cnt++;
				break;
			}
		}
	}

	cout << cnt;

	return 0;
}