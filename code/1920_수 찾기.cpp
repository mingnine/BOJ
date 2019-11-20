#include <stdio.h>
#include <algorithm>
using namespace std;

int num[100001];

void QuickSort2(int arr[], int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		QuickSort2(arr, left, j);

	if (i < right)
		QuickSort2(arr, i, right);
}

bool bisearch(int *arr, int size, int goal)
{
	int st = 0, ed = size - 1;
	int mid;

	while (st <= ed)
	{
		mid = (st + ed) / 2;

		if (goal == arr[mid]) return true;
		else if (goal < arr[mid]) ed = mid - 1;
		else st = mid + 1;
	}
	return false;
}

int main()
{
	int N, M;
	int temp;
	scanf("%d", &N);
	//cin >> N;

	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
		//cin >> num[i];
	}
	//sort(num, num + N);
	QuickSort2(num, 0, N - 1);

	scanf("%d", &M);
	//cin >> M;
	for (int i = 0; i < M; i++) {
		scanf("%d", &temp);
		//cin >> temp;
		if (bisearch(num, N, temp))
			printf("1\n");
			//cout << "1" << endl;
		else
			printf("0\n");
			//cout << "0" << endl;
	}


	return 0;
}