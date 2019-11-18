#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	char c[10] = { 'a','e','i','o','u', 'A', 'E', 'I', 'O', 'U' };
	int cnt;
	while (true)
	{
		cnt = 0;
		getline(cin, s);
		
		if (s[0] == '#') break;
		for (int i = 0; i < s.length(); i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (s[i] == c[j]) cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}