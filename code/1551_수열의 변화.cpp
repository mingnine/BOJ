#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	vector<int> v;
	cin >> n >> k;
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		cin.ignore();
	}


	for (int i = 0; i < k; i++)
	{
		vector<int> ret;
		for (int j = 1; j < v.size(); j++)
		{
			ret.push_back(v[j] - v[j - 1]);
		}
		v = ret;
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
		if (i != v.size() - 1)
			cout << ",";
	}
	return 0;
}