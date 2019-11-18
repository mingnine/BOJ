#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double a, b, c, d, e, f;
	cin >> a >> b >> c;

	d = pow(a, 2);
	e = pow(b, 2);
	f = pow(c, 2);
	e = e + f;
	d = d / e;
	d = sqrt(d);

	cout << floor(b*d) << " " << floor(c*d) << endl;
	return 0;
}