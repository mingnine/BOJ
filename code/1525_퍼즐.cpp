#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

vector<char> v, temp;
queue<vector<char>> q;
map<vector<char>, bool> mchk;

bool chk(vector<char> value)
{
	bool bret = true;
	for (int i = 1; i < 9; i++)
	{
		if (value[i - 1] != i + '0')
		{
			bret = false;
			break;
		}
	}
	return bret;
}

int zeroidx(vector<char> value)
{
	int ret;
	for (int i = 0; i < 9; i++)
	{
		if (value[i] == '0')
		{
			ret = i;
			break;
		}
	}
	return ret;
}

int main()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int in;
			cin >> in;
			v.push_back(in + '0');
		}
	}

	q.push(v);
	int cnt = 0;
	bool bflag = false;
	while (!q.empty())
	{
		int qsize = q.size();
		for (int i = 0; i < qsize; i++)
		{
			vector<char> qv = q.front();
			q.pop();

			if (mchk[qv]) continue;

			if (chk(qv))
			{
				bflag = true;
				break;
			}

			mchk[qv] = true;
			int zero = zeroidx(qv);

			if (zero - 3 >= 0)
			{
				temp = qv;
				swap(temp[zero], temp[zero - 3]);
				q.push(temp);
			}
			if (zero + 3 <= 8)
			{
				temp = qv;
				swap(temp[zero], temp[zero + 3]);
				q.push(temp);
			}
			if (zero - 1 >= 0 && (zero - 1) / 3 == (zero / 3))
			{
				temp = qv;
				swap(temp[zero], temp[zero - 1]);
				q.push(temp);
			}
			if (zero + 1 <= 8 && (zero + 1) / 3 == (zero / 3))
			{
				temp = qv;
				swap(temp[zero], temp[zero + 1]);
				q.push(temp);
			}
		}

		if (bflag)
			break;
		cnt++;
	}

	if (!bflag)
		cout << -1;
	else
		cout << cnt;

	return 0;
}