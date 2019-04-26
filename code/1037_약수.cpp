#include <iostream>
using namespace std;

void quicksort(int *arr, int left, int right)
{
	int pivot = arr[(left + right) / 2];
	int L = left;
	int R = right;

	while (L <= R)
	{
		while (arr[L] < pivot) L++;
		while (arr[R] > pivot)R--;
		if (L <= R)
		{
			int temp = arr[L];
			arr[L] = arr[R];
			arr[R] = temp;
			L++;
			R--;
		}
	}
	if (left < R)
		quicksort(arr, left, R);
	if (L < right)
		quicksort(arr, L, right);
}

int main()
{
	int num;
	int input[50];
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> input[i];
	}
	quicksort(input, 0, num - 1);

	if (num == 1)
		cout << input[0] * input[0];
	else
		cout << input[0] * input[num-1];

	return 0;
}