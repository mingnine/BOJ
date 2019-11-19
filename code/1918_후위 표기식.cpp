#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;



int main()
{
	string s, ret;
	stack<char> st;
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];


		if (c == '+' || c == '-')
		{
			while (!st.empty() && st.top() != '(')
			{
				ret += st.top();
				st.pop();
			}
			st.push(c);
		}
		else if (c == '*' || c == '/')
		{
			while (!st.empty() && (st.top() == '*' || st.top() == '/'))
			{
				ret += st.top();
				st.pop();
			}
			st.push(c);
		}
		else if (c == '(')
		{
			st.push(c);
		}
		else if (c == ')')
		{
			while (!st.empty())
			{
				char ct = st.top();
				st.pop();
				if (ct == '(')
					break;
				ret += ct;
			}
		}
		else
			ret += c;
	}
	while (!st.empty())
	{
		ret += st.top();
		st.pop();
	}
	cout << ret;

	return 0;
}