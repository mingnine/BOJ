#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int cnt = 0;
	string s, ori;
	cin >> s;
	ori = s;

	do {
		next_permutation(s.begin(), s.end());
		
		int prec = -1;
		bool flag = false;
		for (int i = 0; i < s.size(); i++)
		{
			if (prec == s[i])
			{
				flag = true;
				break;
			}
			prec = s[i];
		}
		if (!flag)
			cnt++;
	} while (ori != s);

	cout << cnt;
	return 0;
}