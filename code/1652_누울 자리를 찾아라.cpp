#include <iostream>

using namespace std;


int main()
{
	int T;
	char arr[100][100];
	int result = 0;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < T; j++)
		{
			cin >> arr[i][j];
		}
	}


	int cnt;
	bool chk;
	for (int i = 0; i < T; i++)
	{
		cnt = 0;
		chk = false;
		for (int j = 0; j < T; j++)
		{
			if (arr[i][j] == '.' && chk == false)
				cnt++;
			if (arr[i][j] == 'X')
			{
				cnt = 0;
				chk = false;
			}
			if (cnt >= 2 && chk == false)
			{
				result++;
				chk = true;
			}
		}
	}
	cout << result << " ";
	result = 0;
	for (int i = 0; i < T; i++)
	{
		cnt = 0;
		chk = false;
		for (int j = 0; j < T; j++)
		{
			if (arr[j][i] == '.' && chk == false)
				cnt++;
			if (arr[j][i] == 'X')
			{
				cnt = 0;
				chk = false;
			}
			if (cnt >= 2 && chk == false)
			{
				result++;
				chk = true;
			}
		}
	}
	cout << result << endl;


	return 0;
}
