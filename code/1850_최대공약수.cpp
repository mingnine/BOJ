#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll gcd(ll q, ll p)
{
	if (q < p) swap(q, p);

	while (p > 0)
	{
		ll temp;
		temp = q;
		q = p;
		p = temp % p;
	}
	return q;
}

int main()
{
	ios::sync_with_stdio(false);
	ll a, b;
	cin >> a >> b;
	ll gcdv = gcd(a, b);

	for (int i = 0; i < gcdv; i++)
		cout << 1;
	return 0;
}