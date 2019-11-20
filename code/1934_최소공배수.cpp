#include <iostream>
#define Max(a,b) a>b?a:b
#define Min(a,b) a>b?b:a
using namespace std;


int GCD(int n1, int n2)
{
	int temp;

	while (1)
	{
		temp = n1%n2;
		if (temp == 0)
			break;
		n1 = n2;
		n2 = temp;
	}
	return n2;
}

int main()
{
	int N, a, b;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		cout << a*b / GCD(Max(a, b), Min(a, b)) << endl;
	}
	return 0;
}