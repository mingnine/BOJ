#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a, b;
	getline(cin, a);
	getline(cin, b);

	string copy = b;

	while (a.size() > b.size())
	{
		b += copy;
	}

	string ret;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == ' ')
		{
			ret += ' ';
			continue;
		}
		int ia = a[i] - 'a';
		int ib = b[i] - 'a' + 1;

		int c = ia - ib;
		if (!(c >= 0 && c < 26))
		{
			c += 26;
		}
		ret += c + 'a';
	}
	cout << ret;
	return 0;
}
