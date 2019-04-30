#include <iostream>
using namespace std;

int main()
{
	int n, f;
	cin >> n >> f;

	int comp = n / 100;
	
	int comp2 = -1;
	int temp = 0;
	for (int i = 1;; i++)
	{
		temp = f*i;
		comp2 = temp / 100;
		if (comp2 == comp)
			break;
	}
	printf("%02d", temp % 100);
	return 0;
}