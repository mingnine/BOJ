#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s1, s2, ret;
	cin >> s1 >> s2;

	if (s1[0] == '0')
	{
		string temp;
		bool flag = false;
		for (int i = 0; i < s1.size(); i++)
		{
			if (s1[i] != '0')
			{
				flag = true;
			}
			if (flag)
				temp += s1[i];
		}
		if (temp.size() == 0)
			temp += '0';
		s1 = temp;
	}
	if (s2[0] == '0')
	{
		string temp;
		bool flag = false;
		for (int i = 0; i < s2.size(); i++)
		{
			if (s2[i] != '0')
			{
				flag = true;
			}
			if (flag)
				temp += s2[i];
		}
		if (temp.size() == 0)
			temp += '0';
		s2 = temp;
	}

	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	string *ps;
	if (s1.size() > s2.size())
		ps = &s1;
	else
		ps = &s2;
	int limit = min(s1.size(), s2.size());
	int carry = 0;
	for (int i = 0; i < limit; i++)
	{
		int n1 = s1[i] - '0';
		int n2 = s2[i] - '0';
		int sum = n1 + n2 + carry;
		carry = 0;
		if (sum >= 2)
		{
			carry = 1;
			ret += (sum - 2) + '0';
		}
		else
			ret += sum + '0';
	}

	for (int i = limit; i < (*ps).size(); i++)
	{
		int num = (*ps)[i] - '0';
		int sum = num + carry;
		carry = 0;
		if (sum >= 2)
		{
			carry = 1;
			ret += (sum - 2) + '0';
		}
		else
			ret += sum + '0';
	}
	if (carry == 1)
		ret += '1';

	reverse(ret.begin(), ret.end());

	if (ret[0] == '0')
		cout << 0;
	else
		cout << ret;

	return 0;
}