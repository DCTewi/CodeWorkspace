#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T> T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w? -x: x;
}

const int MAXN = 5e3 + 5;

ll a[MAXN], sum[MAXN];
ll f[MAXN][MAXN], rec[MAXN][MAXN];

int main()
{
    int n = read<int>();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read<int>();
        a[i + n] = a[i];
        sum[i] = sum[i - 1] + a[i];
        rec[i][i] = i;
    }
    for (int i = 1 + n; i <= (n << 1); i++)
    {
        sum[i] = sum[i - 1] + a[i];
        rec[i][i] = i;
    }
    for (int i = (n << 1) - 1; i; i--)
        for (int j = i + 1; j <= (n << 1); j++)
        {
            int jc = 0;
            f[i][j] = max(f[i][j - 1], f[i + 1][j]) + sum[j] - sum[i - 1];

            rec[i][j] = jc;
        }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, f[i][i + n - 1]);
    }
    printf("%d", ans);

    return 0;
}