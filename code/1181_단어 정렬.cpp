#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const string &a, const string &b)
{
	if (a.size() == b.size())
	{
		for (size_t i = 0; i < a.size(); i++)
		{
			if (a[i] == b[i])
				continue;
			else
				return a[i] < b[i];
		}
	}
	return a.size() < b.size();
}

int main()
{
	int n;
	vector<string> vec;
	cin >> n;

	while (n--)
	{
		string s;
		cin >> s;
		vec.push_back(s);
	}

	sort(vec.begin(), vec.end(), comp);
	auto iter = unique(vec.begin(), vec.end());
	vec.erase(iter, vec.end());

	for (string a : vec)
		cout << a << "\n";

	return 0;
}