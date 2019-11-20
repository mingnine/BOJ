#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f

int n, m, ret;
char dna[] = { 'A', 'C', 'G', 'T' };
vector<string> v;
string sret;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		v.push_back(temp);
	}


	for (int i = 0; i < m; i++)
	{
		int cnt, mcnt = INF;
		char mc;
		for (int j = 0; j < 4; j++)
		{
			cnt = 0;
			for (int k = 0; k < n; k++)
			{
				if (v[k][i] != dna[j])
				{
					cnt++;
				}
			}
			if (cnt < mcnt)
			{
				mcnt = cnt;
				mc = dna[j];
			}
		}
		ret += mcnt;
		sret += mc;
	}
	cout << sret << "\n" << ret;

	return 0;
}