#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, m, ret = 2e9;
int dx[] = { 0, 1, 0, 1 };
int dy[] = { 0,0,1,1 };
vector<string> v;

void BW(char& c)
{
	c == 'W' ? c = 'B' : c = 'W';
}

int chk(int x, int y, char c)
{
	int cnt = 0;
	char st = c;
	for (int i = y; i < y + 8; i++)
	{
		char comp = st;
		for (int j = x; j < x + 8; j++)
		{
			if (v[i][j] != comp)
			{
				cnt++;
			}

			if (cnt > ret)
			{
				return -1;
			}
			BW(comp);
		}
		BW(st);
	}

	return cnt;
}

int main()
{
	cin >> n >> m;

	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];



	for (int i = 0; i <= n - 8; i++)
	{
		for (int j = 0; j <= m - 8; j++)
		{
			int retchk = chk(j, i, 'W');
			if (retchk != -1)
				ret = retchk;

			retchk = chk(j, i, 'B');
			if (retchk != -1)
				ret = retchk;
		}
	}

	cout << ret;
	return 0;
}