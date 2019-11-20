#include <iostream>
#include <map>
using namespace std;

void preorder(map<char, pair<char, char>> map, char target)
{
	cout << target;

	if(map[target].first != '.')
		preorder(map, map[target].first);
	if (map[target].second != '.')
		preorder(map, map[target].second);
}

void inorder(map<char, pair<char, char>> map, char target)
{
	if (map[target].first != '.')
		inorder(map, map[target].first);
	cout << target;
	if (map[target].second != '.')
		inorder(map, map[target].second);
}

void postorder(map<char, pair<char, char>> map, char target)
{
	if (map[target].first != '.')
		postorder(map, map[target].first);
	if (map[target].second != '.')
		postorder(map, map[target].second);
	cout << target;
}

int main()
{
	map<char, pair<char, char>> map;
	int n;
	cin >> n;

	while (n--)
	{
		char a, b, c;
		cin >> a >> b >> c;
		map.insert({a, pair<char, char>(b, c)});
	}

	preorder(map, 'A');
	cout << "\n";
	inorder(map, 'A');
	cout << "\n";
	postorder(map, 'A');
	return 0;
}