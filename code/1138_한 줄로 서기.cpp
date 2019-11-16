#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<int> v;
	cin >> n;

	v.resize(n);
	for (int i = 1; i <= n; i++)
	{
		int in;
		int idx = 0;
		cin >> in;
		for (; idx < v.size(); idx++)
		{
			if (in == 0) break;
			if (v[idx] == 0) in--;
		}

		for (; idx < v.size(); idx++)
		{
			if (v[idx] == 0)
			{
				v[idx] = i;
				break;
			}
		}
	}

	for (auto va : v)
	{
		cout << va << " ";
	}
	return 0;
}