#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct _st
{
	int h, m, s;
};




// 숫자가 더 작은지 큰지 비교
// 1 : b 가 a 보다 큼
// 0 : a 가 b 보다 큼
// -1 : a 와 b 서로 같음
int f(_st a, _st b)
{
	if (a.h > b.h)
	{
		return 0;
	}
	else if (a.h < b.h)
	{
		return 1;
	}
	else if (a.h == b.h)
	{
		if (a.m > b.m)
		{
			return 0;
		}
		else if (a.m < b.m)
		{
			return 1;
		}
		else if (a.m == b.m)
		{
			if (a.s > b.s)
			{
				return 0;
			}
			else if (a.s < b.s)
			{
				return 1;
			}
			else if (a.s == b.s)
			{
				return -1;
			}
		}
	}
}

_st stplus(_st a, _st b)
{
	_st ret;
	ret.s = a.s + b.s;
	ret.m = a.m + b.m;
	ret.h = a.h + b.h;
	if (ret.s >= 60)
	{
		ret.s -= 60;
		ret.m += 1;
	}
	if (ret.m >= 60)
	{
		ret.m -= 60;
		ret.h += 1;
	}
	if (ret.h >= 24)
	{
		ret.h -= 24;
	}
	return ret;
}

_st stminus(_st a, _st b)
{
	_st ret;
	ret.s = a.s - b.s;
	ret.m = a.m - b.m;
	ret.h = a.h - b.h;

	if (ret.s < 0)
	{
		ret.m -= 1;
		ret.s += 60;
	}
	if (ret.m < 0)
	{
		ret.h -= 1;
		ret.m += 60;
	}
	if (ret.h < 0)
	{
		ret.h += 24;
	}

	return ret;
}

int main()
{
	_st st, ed, ret;
	char c;
	cin >> st.h >> c >> st.m >> c >> st.s;
	cin >> ed.h >> c >> ed.m >> c >> ed.s;

	if (f(st, ed) == 1)
	{
		ret = stminus(ed, st);
		// ed - st;
	}
	else if (f(st, ed) == 0)
	{
		// st > ed
		_st temp = { 24,0,0 };
		ret = stminus(temp, st);
		ret = stplus(ret, ed);
		// 24 - st + ed;
	}
	// 같은 경우
	else if (f(st, ed) == -1)
	{
		ret = { 0,0,0 };
	}

	if (ret.h < 10)
	{
		cout << 0;
	}
	cout << ret.h << ":";
	if (ret.m < 10)
	{
		cout << 0;
	}
	cout << ret.m << ":";
	if (ret.s < 10)
	{
		cout << 0;
	}
	cout << ret.s;
	return 0;
}