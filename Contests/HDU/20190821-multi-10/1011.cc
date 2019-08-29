////////////         ////////////
//        /////////////        //       Nooooooooooooooooooo
//        //         //        //
//        //         //        //           TIME UP
////////////         ////////////

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 3e5 + 5;
const int LOGN = 25;

ll f[MAXN][LOGN], logn[MAXN + 1];
int a[MAXN];
int n, k, ans = 0;

inline int read()
{
    register int x = 0; register char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

void pre()
{
    logn[1] = 0;
    logn[2] = 1;
    for (register int i = 3; i <= MAXN; i++)
    {
        logn[i] = logn[i / 2] + 1;
    }
}

inline int query(int x, int y)
{
    register int s = logn[y - x + 1];
    return (a[f[x][s]] > a[f[y - (1 << s) + 1][s]])? f[x][s]: f[y - (1 << s) + 1][s];
}

void dfs(int l, int r)
{
    if (l >= r) return;
    int x = query(l, r);
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        for (int i = l; i <= x; i++)
        {
            int p = lower_bound(a + x, a + 1 + r, a[i - 1]) - a;
            ans += r - p + 1;
        }
    }
    else
    {
        for (int i = x; i <= r; i++)
        {
            int p = upper_bound(a + l - 1, a + x, a[i]) - a;
            ans += p - l + 1;
        }
    }
    dfs(l, x - 1);
    dfs(x + 1, r);
}

int main()
{
    int T = read(); pre();
    while (T--)
    {
        memset(f, 0, sizeof(f)); ans = 0;
        n = read(), k = read();
        for (int i = 1; i <= n; i++)
        {
            a[i] = read(); f[i][0] = i;
        }
        for (int j = 1; j <= LOGN; j++)
        {
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
            {
                f[i][j] = (a[f[i][j - 1]] < a[f[i + (1 << (j - 1))][j - 1]])?
                    f[i][j - 1]:
                    f[i + (1 << (j - 1))][j - 1];
            }
        }

        dfs(1, n);
        printf("%d\n", ans);
    }
    return 0;
}

