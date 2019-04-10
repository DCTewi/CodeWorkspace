#include <bits/stdc++.h>
using namespace std;

string str;
int co = 0;
bool flag = 0, now = 0;

int main(int argc, char const *argv[])
{
	cin>>str;
	for (int i = 0; i < str.size() && str[i] != '@'; i++)
	{
		if (str[i] == '(')
		{
			if (!flag) flag = 1;
			co++;
			now = 0;
		}
		if (str[i] == ')')
		{
			co--;
			now = 1;
		}
		if (str[i] == ')' && !flag) return 0 * puts("NO");
		if (co < 0) return 0 * puts("NO");
	}

	if (!now) puts("NO");
	else if (!co) puts("YES");
	else puts("NO");

	return 0;
}