#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXM = 6e1 + 5;
int n, m;
int v[MAXM][3], w[MAXM][3];
int dp[MAXN];

int main(int argc, char const *argv[])
{
	memset(dp, 0, sizeof(dp));
	cin>>n>>m;
	for (int i = 1; i <= m; i++)
	{
		int vv, p, q;
		cin>>vv>>p>>q;
		if (!q)
		{
			v[i][0] = vv;
			w[i][0] = vv * p;
		}
		else
		{
			int index = (v[q][1] == 0? 1: 2);
			v[q][index] = vv;
			w[q][index] = vv * p;
		}
	}

#ifdef TEWILOCAL
	for (int i = 1; i <= m; i++)
	{
		printf("%d:\n", i);
		for (int j = 0; j < 3; j++)
		{
			printf("sub%d:%d, %d ", j, v[i][j], w[i][j]);
		}
		printf("\n");
	}
#endif

	for (int i = 1; i <= m; i++)
	{
		for (int j = n; v[i][0] && j >= v[i][0]; j--)
		{
			if (dp[j] < dp[j - v[i][0]] + w[i][0])
			{
				dp[j] = dp[j - v[i][0]] + w[i][0];
			}
			if (j >= v[i][0] + v[i][1] && dp[j] < dp[j - v[i][0] - v[i][1]] + w[i][0] + w[i][1])
			{
				dp[j] = dp[j - v[i][0] - v[i][1]] + w[i][0] + w[i][1];
			}
			if (j >= v[i][0] + v[i][2] && dp[j] < dp[j - v[i][0] - v[i][2]] + w[i][0] + w[i][2])
			{
				dp[j] = dp[j - v[i][0] - v[i][2]] + w[i][0] + w[i][2];
			}
			if (j >= v[i][0] + v[i][1] + v[i][2] && dp[j] < dp[j - v[i][0] - v[i][1] - v[i][2]] + w[i][0] + w[i][1] + w[i][2])
			{
				dp[j] = dp[j - v[i][0] - v[i][1] - v[i][2]] + w[i][0] + w[i][1] + w[i][2];
			}
		}
	}

	printf("%d\n", dp[n]);
	return 0;
}