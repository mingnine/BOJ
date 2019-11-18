#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct guitar
{
	string name;
	int sum;
};

vector<guitar> v;

bool comp(const guitar &a, const guitar &b)
{
	if (a.name.size() == b.name.size())
	{
		if (a.sum == b.sum)
		{
			return a.name < b.name;
		}
		else
			return a.sum < b.sum;
	}
	else
		return a.name.size() < b.name.size();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;

		int sum = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if ('0' <= s[i] && s[i] <= '9')
				sum += s[i] - '0';
		}
		v.push_back({s, sum});
	}

	sort(v.begin(), v.end(), comp);
	for (auto va : v)
	{
		cout << va.name << "\n";
	}

	return 0;
}