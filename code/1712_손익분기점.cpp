#include <iostream>
using namespace std;

int A, B, C;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C;

	if (C - B <= 0) {
		cout << -1;
	}
	else {
		cout << A / (C - B) + 1;
	}

	return 0;
}