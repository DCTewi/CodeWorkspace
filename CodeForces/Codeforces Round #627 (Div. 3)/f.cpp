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

const int MAXN = 2e4 + 5;

vector<int> g[MAXN];

inline void addedge(int u, int v)
{
    g[u].emplace_back(v);
}

int a[MAXN], dp[MAXN], ans[MAXN], n;

void dfs(int x, int fa = -1)
{
    dp[x] = a[x];
    for (int i = 0, _i = g[x].size(); i < _i; i++)
    {
        int to = g[x][i];
        if (to == fa) continue;

        dfs(to, x);
        dp[x] += max(0, dp[to]);
    }
}

void nexdfs(int x, int now, int fa = -1)
{
    ans[x] = dp[x] + max(0, now);
    int sum = 0;
    for (int i = 0, _i = g[x].size(); i < _i; i++)
    {
        int to = g[x][i];
        if (to == fa) continue;
        sum += max(0, dp[to]);
    }
    for (int i = 0, _i = g[x].size(); i < _i; i++)
    {
        int to = g[x][i];
        if (to == fa) continue;
        if (dp[to] > 0) nexdfs(to, max(0, now + a[x] + sum - dp[to]), x);
        else            nexdfs(to, max(0, now + a[x] + sum),          x);
    }
}

int main()
{
    n = read<int>();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read<int>();
        if (!a[i]) a[i] = -1;
    }
    for (int i = 1; i < n; i++)
    {
        int u = read<int>(), v = read<int>();
        addedge(u, v);
        addedge(v, u);
    }
    dfs(1);
    nexdfs(1, 0);

    for (int i = 1; i <= n; i++)
    {
        printf("%d%c", ans[i], " \n"[i == n]);
    }

    return 0;
}