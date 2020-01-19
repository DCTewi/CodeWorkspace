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

int a[MAXN], sum[MAXN];
int f[MAXN][MAXN];

int main()
{
    int n = read<int>();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read<int>();
        a[i + n] = a[i];
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
    }

    for (int len = 1; len < n; len++)
    {
        for (int l = 1; l + len <= 2 * n; l++)
        {
            int r = l + len;
            for (int k = l; k < r; k++)
            {
                f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r] + sum[r] - sum[l - 1]);
            }
        }
    }

    int ans = -1;
    for (int i = 1; i < n; i++)
    {
        ans = max(ans, f[i][i + n - 1]);
    }

    cout << ans << "\n";

    return 0;
}