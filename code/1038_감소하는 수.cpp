#include <iostream>
using namespace std;
typedef long long ll;

bool chk(ll n)
{
	bool flag = 0;
	int cmp = -1;
	while (n > 0)
	{
		if (cmp < n % 10)
		{
			cmp = n % 10;
			n /= 10;
		}
		else
		{
			flag = true;
			break;
		}
	}
	return flag;
}

int main()
{
	int n, cnt = 0;
	ll result = 0;
	cin >> n;

	for (ll i = 1;cnt < n && cnt < 1023; i++)
	{
		if (!chk(i))
		{
			cnt++;
			result = i;
		}
		else
		{
			ll temp = 10;
			while (chk(i/temp))
				temp *= 10;
			i = (i / temp + 1) * temp - 1;
		}
	}

	if (cnt == 1023)
		cout << -1;
	else
		cout << result;
}