#include <bits/stdc++.h>
using namespace std;

string str;

int find(int x)
{
	int len = 0;
	//Cut up point
	char l = str[x], r = str[x + 1];

	//left
	for (int i = x; ;i--)
	{
		//count
		if (str[i] == l) len++;
		else if (str[i] == 'w') len++;
		else break;
	}
	//right
	for (int i = x + 1; ;i++)
	{
		if (str[i] == r) len++;
		else if (str[i] == 'w') len++;
		else break;
	}

	return len;
}

int main(int argc, char const *argv[])
{
	int ans = -1, n;
	cin>>n>>str;

	//。。。
	str = str + str + str;

	for (int i = n; i < 2 * n; i++)
	{
		if (str[i] == str[i + 1]) continue;

		if (str[i] == 'w')
		{
			str[i] = 'r';
			ans = max(ans, find(i));
			str[i] = 'b';
			ans = max(ans, find(i));
			str[i] = 'w';
		}
		ans = max(ans, find(i));
	}

	ans = min(ans, n);
	if (ans == -1) ans = n;

	cout<<ans<<endl;

	return 0;
}