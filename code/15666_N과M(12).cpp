#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;

void f(vector<int> ret, int idx)
{
	ret.push_back(v[idx]);

	if (ret.size() >= m) {
		for (int i = 0; i < ret.size(); i++) {
			cout << ret[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < v.size(); i++) {
		f(ret, i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++) {
		f(vector<int>(), i);
	};

	return 0;
}