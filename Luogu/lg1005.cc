#include <bits/stdc++.h>
using namespace std;
typedef __int128_t bigint;
typedef __uint128_t ubigint;

const int MAXN = 8e1 + 5;

bigint a[MAXN][MAXN], f[MAXN][MAXN];
bigint ans = 0;
int n, m;

inline void read128(__int128_t &x)
{
    int w = 0; char ch = getchar(); x = 0;
    while (!isdigit(ch))
    {
        w |= ch == '-'; ch = getchar();
    }
    while (isdigit(ch))
    {
        x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();
    }
    x = w? -x: x;
}

inline void print128(__int128_t x)
{
    if (x < 0)
    {
        putchar('-'); x = -x;
    }
    if (x > 9) print128(x / 10);

    putchar(x % 10 + '0');
}

bigint solve(bigint a[])
{
    memset(f, 0, sizeof(f));

    for (int len = 0; len <= m; len++)
    {
        for (int l = 1; l + len <= m; l++)
        {
            int r = l + len;
            f[l][r] = max(f[l + 1][r] + a[l], f[l][r - 1] + a[r]) * 2;
        }
    }
    return f[1][m];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            read128(a[i][j]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        ans += solve(a[i]);
    }

    print128(ans); puts("");

    return 0;
}
