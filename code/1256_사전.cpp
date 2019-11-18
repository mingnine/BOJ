#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
int d[101][101];

int dfs(int A, int Z)
{
	if (A >= n || Z >= m)
		return 1;
	if (d[A][Z] != 0)
		return d[A][Z];

	int L = dfs(A + 1, Z);
	int R = dfs(A, Z + 1);

	return d[A][Z] = min(L + R, 1000000000 + 1);
}

void solve(int A, int Z)
{
	if (A == n && Z == m)
		return;

	int L = 0, R = 0;
	if (A + 1 <= n)
		L = dfs(A + 1, Z);
	if (Z + 1 <= m)
		R = dfs(A, Z + 1);

	if (k <= L)
	{
		cout << "a";
		solve(A + 1, Z);
	}
	else
	{

		cout << "z";
		k -= L;
		solve(A, Z + 1);
	}
}

int main()
{
	cin >> n >> m >> k;

	if (dfs(0, 0) < k)
		cout << -1;
	else
		solve(0, 0);
	return 0;
}