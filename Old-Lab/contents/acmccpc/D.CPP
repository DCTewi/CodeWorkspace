#include <bits/stdc++.h>
using namespace std;

const long long int MAXN = 1e6 + 5;
long long int n, c;
long long int cost[MAXN];

int main(int argc, char const *argv[])
{
	long long int t; scanf("%d", &t);
	while (t--)
	{
		long long int tot = c;
		//input;
		scanf("%lld%lld", &n, &c);
		for (long long int i = 1; i <= n; i++)
		{
			scanf("%lld", &cost[i]);
		}
		for (long long int i = 1; i <= n; i++)
		{
			long long int tmp; scanf("%lld", &tmp);
			cost[i] -= tmp;
			tot += cost[i];
		}

		//check if it could be;
		if (tot < 0) //nope;
		{
			puts("-1");
			continue;
		}
		else //it could be;
		{
			/*long long int now = c;
			for (long long int i = n; i > 0; i--)
			{
				now += cost[i];
				if (now < 0 || i == 1)
				{
					(i == n || (i == 1 && now > 0) )? puts("1"): prlong long intf("%d\n", i + 1);
					break;
				}
			}*/

			for (long long int i = 1; i <= n; i++)
			{
				long long int now = c, flag = 1;
				for (long long int j = i, t = 0; t < n; t++)
				{
					now += cost[j];
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
					printf("%lld\n", i);
					break;
				}
			}
		}
	}

	return 0;
}