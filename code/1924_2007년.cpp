#include <iostream>

using namespace std;

int main()
{
	int month, day;
	int result = 0;
	int cal[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	char day2[8][4] = { { "SUN" } ,{"MON"},{"TUE"},{"WED"},{"THU"},{"FRI"},{"SAT"} };
	cin >> month >> day;

	for (int i = 0; i < month - 1; i++) {
		day += cal[i];
	}
	cout << day2[day % 7] << endl;
	return 0;
}