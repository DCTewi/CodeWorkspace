#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	stack<int> s;
	int now;
	scanf("%d", &now);
	while (now != 0)
	{
		s.push(now);
		scanf("%d", &now);
	}
	while (!s.empty())
	{
		printf("%d ", s.top());
		s.pop();
	}
	return 0;
}