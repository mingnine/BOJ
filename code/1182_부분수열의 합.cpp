#include <iostream>
#include <vector>
using namespace std;

void f(vector<int>* v, vector<int> v2, int idx, int maxidx, int target, int* cnt)
{
	if (maxidx <= idx + 1) return;

	// 선택안하고
	f(v, v2, idx + 1, maxidx, target, cnt);


	// 선택하고
	v2.push_back((*v)[idx + 1]);

	int sum = 0;
	for (int value : v2) sum += value;
	if (sum == target && v2.size() > 0) (*cnt)++;
	f(v, v2, idx + 1, maxidx, target, cnt);
}

int main()
{
	int n, m, cnt = 0;
	vector<int> v;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}

	vector<int> v2;
	f(&v, v2, -1, v.size(), m, &cnt);

	cout << cnt << endl;
	return 0;
}