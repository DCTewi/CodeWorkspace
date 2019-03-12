#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3E5 + 5;
int m, s, t;
int dp[MAXN];

int main()
{
	scanf("%d%d%d", &m, &s, &t);
	//Run only
	for (int i = 1; i <= t; i++)
	{
		if (m >= 10)
		{
			m -= 10;
			dp[i] = dp[i - 1] + 60;	
		}
		else
		{
			m += 4;
			dp[i] = dp[i - 1];
		}
	}
	//Walk instead
	for (int i = 1; i <= t; i++)
	{
		if (dp[i - 1] + 17 > dp[i])
		{
			dp[i] = dp[i - 1] + 17;
		}
	}

	if (dp[t] >= s)
	{
		puts("Yes");
		for (int i = 1; i <= t; i++)
		{
			if (dp[i] >= s)
			{
				printf("%d\n", i);
				return 0;
			}
		}
	}
	else
	{
		puts("No");
		printf("%d\n", dp[t]);
	}

	return 0;
}

