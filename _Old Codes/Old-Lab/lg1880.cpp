/*

枚举长度len in [2, n]
    枚举左端点l in [1, 2 * n - len + 1]
        右端点r = 左端点 + 长度
        枚举断点k in [l, r)

dp[l, r] = max(dp[l, r], dp[l, k] + dp[k + 1, r] + sum[r] - sum[l])
           min
前缀和从1到2*n

*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e2 + 5;
int n;
int a[MAXN], sum[MAXN];
int dpmax[MAXN][MAXN], dpmin[MAXN][MAXN];

int main()
{

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        a[i + n] = a[i];
    }

    for (int i = 1; i <= 2 * n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
    }

    memset(dpmin, 0x3f, sizeof(dpmin));
    for (int i = 1; i <= 2 * n; i++)
    {
        dpmin[i][i] = 0;
    }
    for (int len = 1; len < n; len++)
    {
        for (int l = 1; l + len <= 2 * n; l++)
        {
            {
                int r = l + len;
                for (int k = l; k < r; k++)
                {
                    dpmax[l][r] = max(dpmax[l][r], dpmax[l][k] + dpmax[k + 1][r] + sum[r] - sum[l - 1]);
                    dpmin[l][r] = min(dpmin[l][r], dpmin[l][k] + dpmin[k + 1][r] + sum[r] - sum[l - 1]);
                }
            }
        }
    }

    int maxn = -1, minn = 0x3ffffff;
    for (int i = 1; i < n; i++)
    {
        if (dpmax[i][i + n - 1] > maxn) maxn = dpmax[i][i + n - 1];
        if (dpmin[i][i + n - 1] < minn) minn = dpmin[i][i + n - 1];
    }

    printf("%d\n%d\n", minn, maxn);

    return 0;
}
