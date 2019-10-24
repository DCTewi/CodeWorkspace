#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int x, y, z, a, b, c;
	cin>>x>>y>>z>>a>>b>>c;

	if (a >= x && (a - x + b) >= y && (a + b + c - x - y) >= z)
	{
		puts("YES");
	}
	else
	{
		puts("NO");
	}
	return 0;
}