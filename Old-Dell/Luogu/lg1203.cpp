#include <bits/stdc++.h>
using namespace std;

string str;
int ans = 0, n;

inline int nextt(int n)
{
	return n + 1 >= str.size()? 0: n + 1;
}

inline int prevv(int n)
{
	return n - 1 >= 0? n - 1: str.size() - 1;
}

int getans(int from)
{
	int thisround = 1, now = from;
	//left
	char star = str[now];
	while (str[nextt(now)] == 'w' || str[nextt(now)] == star || star == 'w')
	{
		thisround++;
		now = nextt(now);
		if (star == 'w') star = str[now];
	}
	if (str[now] == star) thisround++;

	now = prevv(from); star = str[now];
	//right
	while (str[prevv(now)] == 'w' || str[prevv(now)] == star || star == 'w')
	{
		thisround++;
		now = prevv(now);
		if (star == 'w') star = str[now];
	}
	if (str[now] == star) thisround++;

	return thisround;
}

int main(int argc, char const *argv[])
{
	cin>>n>>str;

	for (int i = 0; i < str.size(); i++)
	{
		ans = max(ans, getans(i));
	}

	printf("%d\n", ans);
	return 0;
}