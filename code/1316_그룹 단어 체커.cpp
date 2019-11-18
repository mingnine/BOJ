#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	int result = 0;
	string s;

	cin >> T;

	while (T--)
	{
		int alphabet[26] = { 0, };
		bool flag = false;
		char cur;
		cin >> s;

		for (char a : s)
		{
			if (alphabet[(int)a - 97] == 0 || cur == a)
				alphabet[(int)a - 97] = 1;
			else
			{
				flag = true;
				break;
			}
			cur = a;
		}
		if(flag == false)
			result++;
	}
	cout << result << endl;
	return 0;
}