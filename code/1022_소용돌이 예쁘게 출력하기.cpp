#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<vector<int>> v;

int f(int x, int y)
{
	int result;
	// 좌상
	if (x <= 0 && y <= 0)
	{
		// +로 변환
		x *= -1;
		y *= -1;

		if (x > y)
			result = pow(2 * x, 2);
		else
			result = pow(2 * y, 2);
		result += 1;


		if (x > y)
			result += abs(x - y);
		else
			result -= abs(x - y);
	}
	// 우상
	else if (x > 0 && y <= 0)
	{
		y *= -1;

		if (x > y)
			result = pow(2 * x, 2) - 2 * x;
		else
			result = pow(2 * y, 2) - 2 * y;
		result += 1;


		if (x > y)
			result -= abs(x - y);
		else
			result += abs(x - y);

	}
	// 좌하
	else if (x <= 0 && y > 0)
	{
		x *= -1;

		if (x > y)
			result = pow(2 * x, 2) + 2 * x;
		else
			result = pow(2 * y, 2) + 2 * y;
		result += 1;


		if (x > y)
			result -= abs(x - y);
		else
			result += abs(x - y);
	}
	// 우하
	else if (x > 0 && y > 0)
	{
		if (x > y)
			result = pow(2 * (x - 1), 2) + 4 * (x - 1) + 1;
		else
			result = pow(2 * y, 2) + 4 * y;
		result += 1;


		if (x > y)
			result += abs((x - 1) - y);
		else
			result -= abs(x - y);
	}
	return result;
}

int main()
{
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	int maxnum = -1;
	for (int j = r1; j <= r2; j++)
	{
		vector<int> vtemp;
		for (int i = c1; i <= c2; i++)
		{
			int result = f(i, j);
			if (maxnum < result)
				maxnum = result;
			vtemp.push_back(result);
			//printf("%d ", result);
		}
		v.push_back(vtemp);
		//printf("\n");
	}

	int div = 1;
	while (maxnum > 0)
	{
		maxnum /= 10;
		div*=10;
	}
	div /= 10;


	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[0].size(); j++)
		{
			int value = v[i][j];

			while (value / div == 0)
			{
				printf(" ");
				value *= 10;
			}
			printf("%d ", v[i][j]);
		}
			printf("\n");
	}


	return 0;
}