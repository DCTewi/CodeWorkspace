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

const int MAXN = 1e2 + 5;
int m, n;
int a[MAXN][MAXN], dp[MAXN];
int ans = 0, cb, ce, rb, re;
int ncb = 0, nce = 0;

int maxofline()
{
    int res = 0, now = dp[1], l = 1, r = 1;
    for (int i = 2; i <= m; i++)
    {
        if (now > 0)
        {
            now += dp[i]; r = i;
        }
        else
        {
            now = dp[i]; l = r = i;
        }
        
        if (now > res)
        {
            res = now;
            ncb = l, nce = r;
        }
    }
    return res;
}

int main()
{
    n = read<int>(), m = read<int>();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = read<int>();
        }
    }

    for (int i = 1; i <= n; i++)
    {
        memset(dp, 0, sizeof dp);

        for (int j = i; j <= n; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                dp[k] += a[j][k];
            }
            int now = maxofline();
            if (now > ans)
            {
                ans = now;
                rb = i, re = j, cb = ncb, ce = nce;
            }
        }
    }

    printf("%d\n%d %d %d %d\n", ans, rb, re, cb, ce);

    return 0;
}
