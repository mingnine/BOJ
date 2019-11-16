#include <iostream>
#include <string>

using namespace std;

int main()
{
	int arr[26] = { 0, };
	int index = 0;
	string s;

	cin >> s;

	for (int i = 0; i < (int)s.size(); i++)
	{
		arr[toupper(s[i]) - 'A']++;
	}


	for (int i = 0; i < 26; i++)
	{
		if (arr[index] < arr[i])
			index = i;
	}

	for (int i = 0; i < 26; i++)
	{
		if (i == index)
			continue;
		if (arr[i] == arr[index])
		{
			cout << '?' << endl;
			return 0;
		}
	}

	cout << (char)(index + 'A') << endl;

	return 0;
}
