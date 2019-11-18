#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s;
	cin >> s;

	vector<int> vnum;
	vector<char> vc;
	int num = 0;
	int temp = 10;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '+' || s[i] == '-')
		{
			vnum.push_back(num);
			vc.push_back(s[i]);
			num = 0;
		}
		else
		{
			num *= temp;
			num += (s[i] - '0');
		}
	}
	vnum.push_back(num);

	int sum = vnum[0];
	vector<int> vresult;
	for (int i = 0; i < vc.size(); i++)
	{
		// 시작부터 - 나올때까진 더하기
		if (vc[i] == '-')
		{
			vresult.push_back(sum);
			sum = vnum[i + 1];
		}
		else
		{
			sum += vnum[i + 1];
		}
	}
	if (sum != 0)
		vresult.push_back(sum);

	int result = vresult[0];
	for (int i = 1; i < vresult.size(); i++)
	{
		result -= vresult[i];
	}
	cout << result;

	return 0;
}