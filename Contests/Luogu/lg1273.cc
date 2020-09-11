#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e3 + 5;

int n, m;
int head[MAXN], cnt = 1;
int pric[MAXN];
int f[MAXN][MAXN];

struct Edge
{
    int to, next, w;
}edge[MAXN << 2];

void add_edge(int u, int v, int w)
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    edge[cnt].w = w;
    head[u] = cnt++;
}

int dfs(int u)
{
    if (u > n - m) // is a user
    {
        f[u][1] = pric[u];
        return 1;
    }
    int res = 0;
    for (int e = head[u]; e; e = edge[e].next)
    {
        int v = edge[e].to;
        int sub = dfs(v); res += sub;
        for (int j = res; j > 0; j--)
        {
            for (int i = 1; i <= sub; i++)
            {
                if (j - i >= 0)
                {
                    f[u][j] = max(f[u][j], f[u][j - i] + f[v][i] - edge[e].w);
                }
            }
        }
    }
    return res;
}

int main()
{
    #ifndef DEBUG
        ios::sync_with_stdio(0);
    #endif

    cin >> n >> m;
    for (int i = 1; i <= n - m; i++)
    {
        int k; cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int v, w; cin >> v >> w;
            add_edge(i, v, w);
        }
    }
    for (int i = n - m + 1; i <= n; i++)
    {
        cin >> pric[i];
    }

    memset(f, ~0x3f, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        f[i][0] = 0;
    }

    dfs(1);

    for (int i = m; i >= 1; i--)
    {
        if (f[1][i] >= 0)
        {
            return 0 * (bool)(cout << i << "\n");
        }
    }

    return 0;
}