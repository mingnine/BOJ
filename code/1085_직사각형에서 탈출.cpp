#include <iostream>
#define Min(x,y) x>y?y:x
using namespace std;

int main()
{
	int x, y, w, h;
	int result;

	cin >> x >> y >> w >> h;

	result = Min(h - y, y);
	result = Min(result, x);
	result = Min(result, w - x);
	cout << result << endl;
	return 0;
}