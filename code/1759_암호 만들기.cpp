#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> v;
int l, c, aeiou, nonaeiou;
char chk[5] = { 'a', 'e', 'i', 'o', 'u' };

void f(int idx, vector<char> vc)
{
	if (vc.size() > l) return;
	if (v.size() <= idx) return;

	vc.push_back(v[idx]);
	if (vc.size() == l)
	{
		aeiou = 0;
		nonaeiou = 0;
		// 모음 개수 체크
		for (auto value : vc)
		{
			bool flag = false;
			for (int i = 0; i < 5; i++)
			{
				if (value == chk[i])
				{
					flag = true;
					aeiou++;
					break;
				}
			}
			if (!flag)
				nonaeiou++;
		}

		// 모음이 1개이상 2개 이하
		if (aeiou >= 1 && nonaeiou >= 2)
		{
			for (auto value : vc) cout << value;
			cout << "\n";
		}
	}
	f(idx + 1, vc);
	vc.pop_back();

	f(idx + 1, vc);
}

int main()
{
	cin >> l >> c;

	while (c--)
	{
		char input;
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	f(0, vector<char>());
	return 0;
}