#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e4 + 5;
int vtot, n;
int v[MAXN], dp[MAXN];

int main(int argc, char const *argv[])
{
	scanf("%d%d", &vtot, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
	}

	for (int i = 0; i < n; i++)//每件物品
	{
		for (int j = vtot; j >= v[i]; j--)//寻找最优替代
		{
			if (dp[j] < dp[j - v[i]] + v[i])//当前最大不如加上当前物品
			{
				dp[j] = dp[j - v[i]] + v[i];
			}
		}
	}
	return 0 * printf("%d\n",vtot - dp[vtot]);;
}