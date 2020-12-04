#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T> T read()
{
	T x = 0; int ch = getchar(), w = 0;
	while (!isdigit(ch)) w |= ch == '-', ch = getchar();
	while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	return w ? -x : x;
}

const int MAXN = 2e3 + 5;
int a[MAXN];
int dp[MAXN][MAXN];

int main()
{
	int n = read<int>(), h = read<int>(), l = read<int>(), r = read<int>();
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;

	for (int i = 1; i <= n; i++) a[i] = read<int>();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < h; j++)
		{
			int now = (j + a[i]) % h;
			if (l <= now && now <= r)
			{
				dp[i][now] = max(dp[i][now], dp[i - 1][j] + 1);
			}
			else
			{
				dp[i][now] = max(dp[i][now], dp[i - 1][j]);
			}

			now = (j + a[i] - 1) % h;
			if (l <= now && now <= r)
			{
				dp[i][now] = max(dp[i][now], dp[i - 1][j] + 1);
			}
			else
			{
				dp[i][now] = max(dp[i][now], dp[i - 1][j]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < h; i++)
	{
		ans = max(ans, dp[n][i]);
	}
	printf("%d", ans);
	return 0;
}