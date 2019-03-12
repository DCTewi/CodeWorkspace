#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 5;
int dp[MAXN], arcdp[MAXN];
int t[MAXN];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &t[i]);
    }
    t[0] = t[n + 1] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (t[j] < t[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    for (int i = n; i > 0; i--)
    {
        for (int j = n + 1; j > i; j--)
        {
            if (t[j] < t[i])
            {
                arcdp[i] = max(arcdp[i], arcdp[j] + 1);
            }
        }
    }

    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] + arcdp[i] > ans)
        {
            ans = dp[i] + arcdp[i] - 1;
        }
    }

    printf("%d\n", n - ans);

	return 0;
}
