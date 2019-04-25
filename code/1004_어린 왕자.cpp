#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int T, N;
	int cnt;
	int x1, y1, x2, y2;
	int cx, cy, r;

	cin >> T;

	while (T--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> N;
		cnt = 0;

		while (N--)
		{
			cin >> cx >> cy >> r;
			double d1 = sqrt(pow(x1 - cx, 2.0f) + pow(y1 - cy, 2.0f));
			double d2 = sqrt(pow(x2 - cx, 2.0f) + pow(y2 - cy, 2.0f));

			if (d1 <= r && d2 <= r)
				continue;

			if (d1 <= r) cnt++;
			if (d2 <= r) cnt++;

		}

		cout << cnt << endl;
	}
	return 0;
}