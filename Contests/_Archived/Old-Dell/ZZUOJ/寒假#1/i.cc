#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t; cin>>t;
	while (t--)
	{
		int x, n; cin>>x>>n;
		if (n > x) puts("-1");
		else
		{
			int nod = x / n;
			int res = x % n;
			for (int i = 1; i <= n - res; i++)
			{
				printf("%d ", nod);
			}
			for (int i = n - res + 1; i <= n; i++)
			{
				if (i == n)
				{
					printf("%d\n", nod + 1);
				}
				else
				{
					printf("%d ", nod + 1);
				}
			}
		}
	}
	return 0;
}
