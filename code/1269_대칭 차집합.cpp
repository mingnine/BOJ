#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a, b, in;
vector<int> va, vb;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;

	for (int i = 0; i < a; i++)
	{
		cin >> in;
		va.push_back(in);
	}
	for (int i = 0; i < b; i++)
	{
		cin >> in;
		vb.push_back(in);
	}

	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());

	int idxA = 0, idxB = 0, ret = 0;

	while (idxA < va.size() && idxB < vb.size())
	{
		if (va[idxA] == vb[idxB])
		{
			idxA++; idxB++;
		}
		else if (va[idxA] < vb[idxB])
		{
			idxA++; ret++;
		}
		else if (va[idxA] > vb[idxB])
		{
			idxB++; ret++;
		}
	}
	while (idxA++ < va.size()) ret++;
	while (idxB++ < vb.size()) ret++;

	cout << ret;
	return 0;
}