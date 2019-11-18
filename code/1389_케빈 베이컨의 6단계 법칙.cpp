#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int d[101][101];
int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				d[i][j] = 0;
			else
				d[i][j] = 99;
		}

	for (int i = 0; i < m; i++)
	{
		int in1, in2;
		cin >> in1 >> in2;
		d[in1 - 1][in2 - 1] = 1;
		d[in2 - 1][in1 - 1] = 1;
	}

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);


	int result = 99;
	int idx;
	for (int i = 0; i < n; i++)
	{
		int cmp = 0;
		for (int j = 0; j < n; j++)
			if (d[i][j] != 99)
				cmp += d[i][j];
		if (result > cmp)
		{
			result = cmp;
			idx = i;
		}
	}

	cout << idx + 1;

	return 0;
}