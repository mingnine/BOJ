#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int find(int a)
{
	if (v[a] == a) return a;
	else return v[a] = find(v[a]);
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i <= n; i++)
		v.push_back(i);

	while (m--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		// 합집합
		if (a == 0)
		{
			int x = find(b);
			int y = find(c);
			v[x] = y;
		}
		// 원소 확인
		else
		{
			if (find(b) == find(c))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

	return 0;
}