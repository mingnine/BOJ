#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int m[3] = { 1,2,4 };
	int midx = 0, sum = 0;
	string s;
	string result;
	cin >> s;
	reverse(s.begin(), s.end());


	for (int i = 0; i < s.size(); i++)
	{
		int n = s[i] - '0';
		n *= m[midx];
		sum += n;
		if (midx == 2)
		{
			result += sum + '0';
			sum = 0;
		}
		midx = (midx + 1) % 3;
	}
	if (midx != 0)
		result += sum + '0';
	reverse(result.begin(), result.end());
	cout << result;
	return 0;
}