#include <iostream>
using namespace std;

int main()
{
	char chessboard[10][10];
	int chk = 0;
	int cnt = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> chessboard[i][j];
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (chk; chk < 8; chk += 2)
		{
			if (chessboard[i][chk] == 'F') cnt++;
		}
		chk = chk % 2 == 0 ? 1 : 0;
	}
	cout << cnt << endl;
	return 0;
}