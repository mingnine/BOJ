#include <iostream>
using namespace std;

int gcd(int p, int q)
{
	if (q == 0) return p;
	return gcd(q, p%q);
}

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	a *= d;
	c *= b;
	b *= d;
	a += c;

	int g = gcd(b, a);

	a /= g;
	b /= g;

	cout << a << " " << b;

}