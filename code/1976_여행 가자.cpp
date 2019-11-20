#include <iostream>
#include <vector>
using namespace std;

int d[201][201];
int main()
{
	int n, m;
	vector<int> v;
	cin >> n >> m;
	v.resize(m);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> d[i][j];

	for (int i = 1; i <= n; i++)
		d[i][i] = 1;

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (d[i][k] == 1 && d[k][j] == 1)
					d[i][j] = 1;

	for (int i = 0; i < m; i++)
		cin >> v[i];

	bool flag = false;
	for (int i = 1; i < v.size(); i++)
		if (d[v[i - 1]][v[i]] == 0)
			flag = true;

	if (flag)
		cout << "NO";
	else
		cout << "YES";

	return 0;
}