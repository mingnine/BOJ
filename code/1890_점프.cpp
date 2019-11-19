#include <iostream>
using namespace std;

int d[101][101];
long long chk[101][101];
int n;
long long result;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> d[i][j];
		}
	}

	int dist = d[0][0];
	chk[0][dist]++;
	chk[dist][0]++;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == n - 1 && j == n - 1) continue;

			if (chk[i][j] > 0)
			{
				dist = d[i][j];
				if(j+dist < n)
					chk[i][j + dist] += chk[i][j];
				if (i + dist < n)
					chk[i + dist][j] += chk[i][j];
			}
		}
	}

	cout << chk[n-1][n-1];
	return 0;
}