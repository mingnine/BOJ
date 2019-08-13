#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s[3];
	cin >> s[0] >> s[1] >> s[2];

	long long result = 0;
	long long mulitply = 10;
	for (int i = 0; i < 2; i++)
	{
		long long num = 0;
		if (s[i] == "brown") num = 1;
		if (s[i] == "red") num = 2;
		if (s[i] == "orange") num = 3;
		if (s[i] == "yellow") num = 4;
		if (s[i] == "green") num = 5;
		if (s[i] == "blue") num = 6;
		if (s[i] == "violet") num = 7;
		if (s[i] == "grey") num = 8;
		if (s[i] == "white") num = 9;
		num *= mulitply;
		result += num;
		mulitply /= 10;
	}
	long long i = 2;
	long long num = result;
	if (s[i] == "brown") num *= 1e1;
	if (s[i] == "red") num *= 1e2;
	if (s[i] == "orange") num *= 1e3;
	if (s[i] == "yellow") num *= 1e4;
	if (s[i] == "green") num *= 1e5;
	if (s[i] == "blue") num *= 1e6;
	if (s[i] == "violet") num *= 1e7;
	if (s[i] == "grey") num *= 1e8;
	if (s[i] == "white") num *= 1e9;

	cout << num;
	return 0;
}