#include <iostream>
using namespace std;

int N;
int tri[501][501];
int sumtri[501][501];

int main()
{
	int max = 0;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin>>tri[i][j];
		}
	}

	for (int i = 2; i <= N; i++)
	{
		tri[i][1] = tri[i][1] + tri[i-1][1];
		for (int j = 2; j <= i; j++)
		{
			tri[i][j] = tri[i][j] + (tri[i - 1][j] > tri[i - 1][j - 1] ? tri[i - 1][j] : tri[i - 1][j - 1]);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (max < tri[N][i])
			max = tri[N][i];
	}

	cout << max << endl;
	
	return 0;
}