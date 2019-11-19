#include <iostream>
#include <vector>
using namespace std;

int v[1000][1000];

int main()
{
	int n, target, tx, ty;
	cin >> n >> target;

	int mid = n / 2;
	int num = 1;
	int x = mid;
	int y = mid;
	int endx = x;
	int endy = y;
	int flagcnt = 0;
	int flag = 0;	// 북 동 남 서

	v[y][x] = num++;
	tx = x;
	ty = y;
	while (n*n >= num)
	{
		if (flag == 0)
		{
			y--;
			for (int i = 0; i < flagcnt / 2 + 1; i++)
				endy--;
			if (endy < 0)
				endy = 0;
			for (; y >= endy; y--)
			{
				if (num == target)
				{
					tx = x;
					ty = y;
				}
				v[y][x] = num++;
			}
			y++;
			flagcnt++;
			flag = (flag + 1) % 4;
		}
		else if (flag == 1)
		{
			x++;
			for (int i = 0; i < flagcnt / 2 + 1; i++)
				endx++;

			for (; x <= endx; x++)
			{
				if (num == target)
				{
					tx = x;
					ty = y;
				}
				v[y][x] = num++;
			}
			x--;
			flagcnt++;
			flag = (flag + 1) % 4;
		}
		else if (flag == 2)
		{
			y++;
			for (int i = 0; i < flagcnt / 2 + 1; i++)
				endy++;

			for (; y <= endy; y++)
			{
				if (num == target)
				{
					tx = x;
					ty = y;
				}
				v[y][x] = num++;
			}
			y--;
			flagcnt++;
			flag = (flag + 1) % 4;
		}
		else if (flag == 3)
		{
			x--;
			for (int i = 0; i < flagcnt / 2 + 1; i++)
				endx--;

			for (; x >= endx; x--)
			{
				if (num == target)
				{
					tx = x;
					ty = y;
				}
				v[y][x] = num++;
			}
			x++;
			flagcnt++;
			flag = (flag + 1) % 4;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", v[i][j]);
		}
		printf("\n");
	}
	printf("%d %d", ty + 1, tx + 1);
	return 0;
}