#include <iostream>
#define Min(x,y)	((x>y)?y:x)
using namespace std;

int main()
{
	int N, r, g, b, r2, g2, b2;
	cin >> N;

	cin >> r >> g >> b;

	for (int i = 1; i < N; i++)
	{
		cin >> r2 >> g2 >> b2;
		r2 = r2 + Min(g, b);
		g2 = g2 + Min(r, b);
		b2 = b2 + Min(r, g);
		r = r2;
		g = g2;
		b = b2;
	}
	cout << Min(Min(r, g), b) << endl;
	return 0;
}