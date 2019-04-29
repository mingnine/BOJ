#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct _tree
{
	int parent;
	vector<int> child;
};

int n, m, rootidx, ret;
vector<_tree> v;


void cntleaf(int idx)
{
	if (v[idx].child.empty() || (v[idx].child.size() == 1 && v[idx].child[0] == m))
	{
		ret++;
		return;
	}
	
	for (int i = 0; i < v[idx].child.size(); i++)
	{
		int cidx = v[idx].child[i];

		if (cidx == m) continue;

		cntleaf(v[idx].child[i]);
	}
}


int main()
{
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		int in;
		cin >> in;
		if (in == -1)
			rootidx = i;

		v[i].parent = in;
		if(in != -1)
			v[in].child.push_back(i);
	}
	cin >> m;

	if (!(n == 1 && m == 0))
	{
		if(rootidx != m)
			cntleaf(rootidx);
	}
	cout << ret;
	return 0;
}