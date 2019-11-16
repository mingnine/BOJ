#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int n, m;
vector<int> v;
set<vector<int>> s;

void f(vector<int> ret, int idx)
{
	ret.push_back(v[idx]);

	if (ret.size() >= m) {
		vector<int> temp;
		for (int i = 0; i < ret.size(); i++) {
			temp.push_back(ret[i]);
		}

		s.insert(temp);
		return;
	}

	for (int i = idx + 1; i < v.size(); i++) {
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

	for (int i = 0; i < v.size(); i++) {
		f(vector<int>(), i);
	};

	for (auto siter : s) {
		for (auto value : siter) {
			cout << value << " ";
		}
		cout << "\n";
	}

	return 0;
}