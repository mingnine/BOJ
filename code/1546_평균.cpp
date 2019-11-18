#include <iostream>

using namespace std;

int maxnum(int *num, int size)
{
	int max = num[0];
	for (int i = 0; i < size; i++)
	{
		if (max <= num[i])
			max = num[i];
	}
	return max;
}


int main()
{
	int T;
	int *a;
	int max;
	double result = 0.0f;

	cin >> T;

	a = new int[T];

	for (int i = 0; i < T; i++)
	{
		cin >> a[i];
	}

	max = maxnum(a, T);


	for (int i = 0; i < T; i++)
	{
		double test = (double)a[i] / (double)max * 100.0;
		result += test;
	}

	cout << result / T << endl;

	delete[] a;
	return 0;
}
