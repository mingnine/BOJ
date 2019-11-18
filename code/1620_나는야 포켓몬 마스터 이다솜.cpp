#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> ma;
vector<string> v;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	string s;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		v.push_back(s);
		ma[s] = i + 1;
	}


	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if ('0' <= s[0] && s[0] <= '9')
		{
			int num = atoi(s.c_str());
			cout << v[num - 1] << "\n";
		}
		else
		{
			cout << ma[s] << "\n";
		}
	}

	return 0;
}