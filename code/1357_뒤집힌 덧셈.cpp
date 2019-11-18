#include <iostream>
using namespace std;

int reverse(int a)
{
	int temp = 0;
	while (a > 0)
	{
		temp *= 10;
		temp += a % 10;
		a /= 10;
	}
	return temp;
}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);

	cout << reverse(reverse(a) + reverse(b)) << endl;


	return 0;
}