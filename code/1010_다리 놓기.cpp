#include <iostream>
using namespace std;

int N,a,b;
int dp[40][40];

void initdp()
{
	for (int i = 1; i < 30; i++) {
		dp[1][i] = i;
	}
	for (int i = 2; i < 30; i++) {
		for (int j = i; j < 30; j++) {
			if (i == j) dp[i][j] = 1;
			else {
				dp[i][j] = dp[i][j - 1] + dp[i-1][j-1];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N;

	initdp();
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		cout << dp[a][b] << "\n";
	}
}