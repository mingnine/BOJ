#include <iostream>
using namespace std;

int arr[2200][2200];
int a, b, c;

bool isfill(int x, int y, int size)
{
	int chk = arr[y][x];
	for (int i = y; i < y + size; i++)
		for (int j = x; j < x + size; j++)
			if (arr[i][j] != chk)
				return false;
	return true;
}

void f(int x, int y, int size)
{
	if (isfill(x, y, size))
	{
		if (arr[y][x] == -1)
			a++;
		else if (arr[y][x] == 0)
			b++;
		else
			c++;
	}
	else
	{
		int resize = size / 3;
		f(x, y, resize);
		f(x + resize, y, resize);
		f(x + resize + resize, y, resize);

		f(x, y + resize, resize);
		f(x + resize, y + resize, resize);
		f(x + resize + resize, y + resize, resize);

		f(x, y + resize + resize, resize);
		f(x + resize, y + resize + resize, resize);
		f(x + resize + resize, y + resize + resize, resize);
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	f(0, 0, n);

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	return 0;
}