#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int alp[26] = { 0, };
	vector<char> v;
	cin >> n;
	
	while (n--)
	{
		string s;
		cin >> s;

		alp[s[0] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (alp[i] >= 5)
			v.push_back(i + 'a');
	}

	sort(v.begin(), v.end());

	if (v.empty())
		cout << "PREDAJA";
	else
		for (auto value : v)
			cout << value;

	return 0;
}