#include <iostream>
#include <string>
using namespace std;

int main()
{
	string n, s;
	cin >> n;

	for(int i=0;i<n.size();i++)
	{
		int k = n[i] - '0';
		if (k == 0) s += "000";
		if (k == 1) s += "001";
		if (k == 2) s += "010";
		if (k == 3) s += "011";
		if (k == 4) s += "100";
		if (k == 5) s += "101";
		if (k == 6) s += "110";
		if (k == 7) s += "111";
	}

	int idx = -1;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '1')
		{
			idx = i;
			break;
		}
	}

	if (idx == -1)
		cout << 0;
	else
		for (int i = idx; i < s.size(); i++)
			cout << s[i];
	
	return 0;
}