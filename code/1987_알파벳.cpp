#include <iostream>
#include <string>
using namespace std;

int n, m;
char board[21][21];
bool alp[26];
int result = 0;

void f(int x, int y, int cnt)
{
	int cur = board[y][x] - 'A';
	if (alp[cur]) return;

	alp[cur] = true;
	cnt++;

	if (result < cnt)
		result = cnt;

	if (x + 1 < m)
		f(x + 1, y, cnt);
	if (x - 1 >= 0)
		f(x - 1, y, cnt);
	if (y + 1 < n)
		f(x, y + 1, cnt);
	if (y - 1 >= 0)
		f(x, y - 1, cnt);

	alp[cur] = false;
}

int main()
{
	cin >> n >> m;
	getchar();
	for (int i = 0; i < n; i++)
	{
		string s;
		getline(cin, s);
		for (int j = 0; j < m; j++)
		{
			board[i][j] = s[j];
		}
	}

	f(0, 0, 0);

	cout << result << endl;
	return 0;
}