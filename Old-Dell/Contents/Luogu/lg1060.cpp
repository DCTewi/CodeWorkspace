#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e4 + 5;
int n, m;
int v[30], w[30];
int dp[MAXN * 5];

int main(int argc, char const *argv[])
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &v[i], &w[i]);
		w[i] *= v[i];
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = n; j >= v[i]; j--)
		{
			if (dp[j] < dp[j - v[i]] + w[i])
			{
				dp[j] = dp[j - v[i]] + w[i];
			}
		}
	}

	printf("%d\n", dp[n]);
	return 0;
}