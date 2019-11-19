#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
int arr[100001];
vector<char> ans;
stack<int> s;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int pos = 0;
	for (int i = 1; i <= n; i++)
	{
		s.push(i);
		ans.push_back('+');

		while (!s.empty() && arr[pos] == s.top())
		{
			pos++;
			s.pop();
			ans.push_back('-');
		}
	}

	if (!s.empty())
		cout << "NO" << "\n";
	else
		for (auto iter : ans)
			cout << iter << "\n";

	return 0;
}
