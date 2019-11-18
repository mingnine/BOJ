#include <iostream>
using namespace std;
typedef long long ll;
ll N, ans, tc, fc;
int main() {
	scanf("%lld", &N);
	ans = 1;
	for (int i = 2; i <= N; i *= 2)
		tc += N / i;
	for (int i = 5; i <= N; i *= 5)
		fc += N / i;
	for (int i = 1; i <= N; i++) {
		ll x = i;
		while (x % 2 == 0)  x /= 2;
		while (x % 5 == 0)  x /= 5;
		ans = (ans * x) % 100000;
	}
	tc -= fc;
	while (tc--)
		ans = (ans * 2) % 100000;
	printf("%05lld\n", ans);
	return 0;
}