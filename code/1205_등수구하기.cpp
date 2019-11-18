#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int n, score, p;
vector<int> v;

int main()
{
	cin >> n >> score >> p;
	
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int rank = 1;
	int equal = 0;

	for (int i = 0; i < n; i++)
	{
		if (v[i] > score)
			rank++;
		else if (v[i] == score)
			equal++;
		else
			break;
	}

	if (rank + equal > p)
		cout << -1;
	else
		cout << rank;

	return 0;
}