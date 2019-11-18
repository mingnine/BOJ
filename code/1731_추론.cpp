#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;

int main()
{
	cin >> n;
	while (n--)
	{
		int in;
		cin >> in;
		v.push_back(in);
	}

	bool chk = true;
	int pre = v[1] - v[0];
	for (int i = 2; i < v.size(); i++)
	{
		if (pre != v[i] - v[i - 1])
		{
			chk = false;
			break;
		}
	}
	if (chk)
	{
		cout << v.back() + pre;
	}
	else
	{
		cout << v.back() * (v[1] / v[0]);
	}

	return 0;
}