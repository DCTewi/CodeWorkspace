#pragma GCC optimize(2)
#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;
typedef long long ll;

template <class T> T read()
{
    T x = 0; int ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

const int MAXN = 1e4 + 5;
const int UPLIMIT = 1e7 + 5;

struct Node
{
    ll l, r;
} dat[MAXN] ;
int vis[MAXN], ans = 0;

void dfs(int l, int r, int p)
{
    if (!p) return;
    Node &now = dat[p];
    if (now.l <= r && now.r >= l)
    {
        if (!vis[p]) vis[p] = 1, ans++;
        if (now.l > l) dfs(l, now.l - 1, p - 1);
        if (now.r < r) dfs(now.r + 1, r, p - 1);
    }
    else dfs(l, r, p - 1);
}

void init()
{
    ans = 0;
    memset(vis, 0, sizeof(vis));
}

int main()
{
    int T = read<int>();
    while (T--)
    {
        init();
        int n = read<int>();
        for (int i = 1; i <= n; i++)
        {
            dat[i].l = read<int>();
            dat[i].r = read<int>();
        }

        dfs(0, UPLIMIT, n);

        printf("%d\n", ans);
    }
    return 0;
}