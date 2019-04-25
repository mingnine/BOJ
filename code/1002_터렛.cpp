#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	int testcase;
	int x1, y1, r1;
	int x2, y2, r2;

	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		// 두 원의 중점간의 거리
		double a = sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));

		// 두 점이 같을 경우
		if (x1 == x2 && y1 == y2)
		{
			// 무한대
			if (r1 == r2)
			{
				cout << -1 << endl;
			}
			// 답 없음
			else
			{
				cout << 0 << endl;
			}
		}
		// 답 없음
		else if (a > r1 + r2 || a < abs(r1 - r2))
		{
			cout << 0 << endl;
		}
		// 답 하나
		else if (a == r1 + r2 || a == abs(r1 - r2))
		{
			cout << 1 << endl;
		}
		// 답 두개
		else if (a < r1 + r2 && a > abs(r1 - r2))
		{
			cout << 2 << endl;
		}
	}

	return 0;
}