#include <iostream>
#include <string>
#include <list>
using namespace std;

list<char> li;
list<char>::iterator iter;
string s;
int t;
char c;

void retpr()
{
	for (auto aiter = li.begin(); aiter != li.end(); aiter++)
	{
		cout << *aiter;
	}
	cout << "\n";
	//cout << (*iter) << "\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s >> t;

	for (int i = 0; i < s.size(); i++)
		li.push_back(s[i]);

	iter = li.end();
	while (t--)
	{
		cin >> c;
		if (c == 'L')
		{
			if (iter != li.begin())
				iter--;
		}
		else if (c == 'D')
		{
			if (iter != li.end())
				iter++;
		}
		else if (c == 'B')
		{
			if (iter != li.begin())
			{
				iter--;
				iter = li.erase(iter);
			}
		}
		else if (c == 'P')
		{
			cin >> c;
			if (iter == li.end())
			{
				li.push_back(c);
			}
			else
			{
				iter = li.insert(iter, c);
				iter++;
			}
		}
	}
	retpr();
	return 0;
}