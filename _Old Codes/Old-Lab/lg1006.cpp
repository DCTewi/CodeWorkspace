#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int v[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];

int maxm(int a, int b, int c, int d)
{
	if (a < b) a = b;
	if (a < c) a = c;
	if (a < d) a = d;
	return a;
}

int main()
{
	int n, m; cin>>n>>m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &v[i][j]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				for (int l = j + 1; l <= m; l++)
				{
					dp[i][j][k][l] = maxm(
						dp[i - 1][j][k - 1][l],
						dp[i - 1][j][k][l - 1],
						dp[i][j - 1][k][l - 1],
						dp[i][j - 1][k - 1][l]
					) + v[i][j] + v[k][l];
				}
			}
		}
	}

	printf("%d\n", dp[n][m - 1][n - 1][m]);

	return 0;
}
