#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int a[MAXN], b[MAXN];

int main(int argc, char const *argv[])
{
	int t; scanf("%d", &t);
	while (t--)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));

		int n, c; scanf("%d%d", &n, &c);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &b[i]);
		}
		int out = 0;
		for (int i = 1; i <= n; i++)
		{
			int now = c, flag = 1;
			for (int j = i, t = 0; t < n; t++)
			{
				now += a[j];
				now -= b[j];
				if (now < 0)
				{
					flag = 0;
					break;
				}
				if (j == n) j = 1;
				else j++;
			}

			if (flag)
			{
				printf("%d\n", i);
				out = 1;
				break;
			}
		}

		if (!out) puts("-1");
	};
	return 0;
}
