#include <bits/stdc++.h>
using namespace std;

int n, m, tmp, c1, c2, c3;

int main(int argc, char const *argv[])
{
	int t; cin>>t;
	while (t--)
	{
		int ans = 0;
		cin>>n>>m;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &tmp);
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &c1, &c2, &c3);
			if (c1 > 1 && c1 < 5)
			{
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}