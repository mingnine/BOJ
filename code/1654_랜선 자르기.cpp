#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	long long k, n;
	long long  temp;
	long long  l, r, mid;
	long long  result;
	vector<long long > vec;
	cin >> k >> n;

	for (int i = 0; i < k; i++)
	{
		cin >> temp;
		vec.push_back(temp);
	}


	l = 1;
	r = *max_element(vec.begin(), vec.end());
	long long  cnt = 0;
	while (l <= r)
	{
		cnt = 0;
		mid = (l + r) / 2;
		for (auto iter = vec.begin(); iter != vec.end(); iter++)
		{
			cnt += (*iter) / mid;
		}
		if (cnt >= n)
		{
			result = mid;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}

	cout << result << endl;

	return 0;
}

