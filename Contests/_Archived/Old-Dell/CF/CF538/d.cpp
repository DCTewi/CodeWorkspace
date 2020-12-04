#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e3 + 5;
int n;
int c[MAXN], d[MAXN], top = 0;
int dp[MAXN][MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		cin>>c[i];
		if (c[i] != c[i - 1])
		{
			d[++top] = c[i];
		}
	}

	for (int i = 2; i <= top; i++)
	{
		for (int l = 1; l <= top; l++)
		{
			int r = l + i - 1;
			if (r > top)
			{
				break;
			}

			if (d[l] != d[r])
			{
				dp[l][r] = min(dp[l][r - 1], dp[l + 1][r]) + 1;
			}
			else if (i == 2)
			{
				dp[l][r] = 0;
			}
			else
			{
				dp[l][r] = dp[l + 1][r - 1] + 1;
			}
		}
	}

	cout<<dp[1][top]<<endl;
	return 0;
}