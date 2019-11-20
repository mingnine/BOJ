#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f;

bool bPrime[10001];

void initPrime()
{
	for (int i = 2; i < 10001; i++)
		bPrime[i] = true;
	for (int i = 2; i < 10001; i++)
	{
		if (bPrime[i])
		{
			for (int j = i + i; j < 10001; j += i)
			{
				bPrime[j] = false;
			}
		}
	}
}

vector<int> swapPrime(int n)
{
	vector<int> v;
	int orin = n;
	int num[4];
	num[0] = n / 1000; n %= 1000;
	num[1] = n / 100; n %= 100;
	num[2] = n / 10; n %= 10;
	num[3] = n;

	// 1000
	int plus;
	plus = num[1] * 100 + num[2] * 10 + num[3];
	for (int i = 1; i <= 9; i++)
	{
		int temp = i * 1000 + plus;
		if (bPrime[temp])
			v.push_back(temp);
	}

	// 100
	plus = num[0] * 1000 + num[2] * 10 + num[3];
	for (int i = 0; i <= 9; i++)
	{
		int temp = i * 100 + plus;
		if (bPrime[temp])
			v.push_back(temp);
	}

	// 10
	plus = num[0] * 1000 + num[1] * 100 + num[3];
	for (int i = 0; i <= 9; i++)
	{
		int temp = i * 10 + plus;
		if (bPrime[temp])
			v.push_back(temp);
	}

	// 1
	plus = num[0] * 1000 + num[1] * 100 + num[2] * 10;
	for (int i = 0; i <= 9; i++)
	{
		int temp = i + plus;
		if (bPrime[temp])
			v.push_back(temp);
	}
	return v;
}

void f(int n, int target)
{
	bool bVisit[10001] = { 0, }; 
	queue<int> q;
	q.push(n);
	//bVisit[n] = true;


	int cnt = 0;
	bool endflag = false;
	while (!q.empty())
	{
		int qsize = q.size();
		for (int i = 0; i < qsize; i++)
		{
			int qint = q.front();
			q.pop();

			if (qint == target)
			{
				endflag = true;
				break;
			}

			if (bVisit[qint]) continue;
			bVisit[qint] = true;


			auto v2 = swapPrime(qint);
			for (int j = 0; j < v2.size(); j++)
			{
				if (bVisit[v2[j]]) continue;
				q.push(v2[j]);
			}
		}
		if (endflag) break;
		cnt++;
	}
	if (endflag)
		cout << cnt << "\n";
	else
		cout << "Impossible\n";
}

int main()
{
	initPrime();

	int t, a, b;
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		f(a, b);
	}
	return 0;
}