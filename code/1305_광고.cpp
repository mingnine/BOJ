#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getPi(string s)
{
	int n = s.size();
	vector<int> pi(n);

	int j = 0;
	for (int i = 1; i < n; i++)
	{
		while (j>0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])
			pi[i] = ++j;
	}

	return pi;
}

int main()
{
	int n;
	string s;
	cin >> n >> s;
	auto pi = getPi(s);

	cout << n - pi[n - 1];
}