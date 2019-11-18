#include <iostream>

using namespace std;

int main()
{
	int er, sr, mr, e = 1, s = 1, m = 1;
	cin >> er >> sr >> mr;

	int cnt = 1;
	while (true)
	{
		if (e > 15) e = 1;
		if (s > 28) s = 1;
		if (m > 19) m = 1;
		if (e == er && s == sr && m == mr) break;

		e++; s++; m++; cnt++;
	}
	cout << cnt << endl;
}