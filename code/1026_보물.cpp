#include <iostream>
using namespace std;

void selectionSort(int arr[], int size)
{
	int min, temp;
	for (int i = 0; i < size; i++)
	{
		int min = i;
		for (int j = i + 1; j < size; j++)
			if (arr[min] > arr[j]) min = j;
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

void reverse_selectionSort(int arr[], int size)
{
	int max, temp;
	for (int i = 0; i < size; i++)
	{
		max = i;
		for (int j = i + 1; j < size; j++)
			if (arr[max] < arr[j]) max = j;
		temp = arr[i];
		arr[i] = arr[max];
		arr[max] = temp;
	}
}

int main()
{
	int N, result = 0;
	cin >> N;

	int *a = new int[N];
	int *b = new int[N];

	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N; i++) cin >> b[i];

	selectionSort(a, N);
	reverse_selectionSort(b, N);

	for (int i = 0; i < N; i++) result += a[i] * b[i]; 

	cout << result << endl;
	delete[] a;
	delete[] b;
	return 0;
}