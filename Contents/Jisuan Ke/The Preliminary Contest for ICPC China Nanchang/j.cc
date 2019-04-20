#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;

struct Edge
{
    int to, nex, cost;

}edge[2 * MAXN];
int depth[MAXN], fa[MAXN][50], lg[MAXN], head[MAXN];
int tot;

void add(int x, int y, int c)
{
    edge[++tot].to = y;
    edge[tot].nex = head[x];
    edge[tot].cost = c;
    head[x] = tot;
}

void dfs(int f, int fath)
{
    depth[f] = depth[fath] + 1;
    fa[f][0] = fath;
    for (int i = 1; (1 << i) <= depth[f]; i++)
    {
        fa[f][i] = fa[fa[f][i - 1]][i - 1];
    }
    for (int i = head[f]; i; i = edge[i].nex)
    {
        if (edge[i].to != fath)
        {
            dfs(edge[i].to, f);
        }
    }
}

int lca(int x, int y)
{
    if (depth[x] < depth[y])
    {
        swap(x, y);
    }

    while (depth[x] > depth[y])
    {
        x = fa[x][lg[depth[x] - depth[y]] - 1];
    }

    if (x == y) return x;
    for (int k = lg[depth[x]] - 1; k >= 0; k--)
    {
        if (fa[x][k] != fa[y][k])
        {
            x = fa[x][k];
            y = fa[y][k];
        }
    }
    return fa[x][0];
}
int n, m;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y, c; cin>>x>>y>>c;
        add(x, y, c); add(y, x, c);
    }
    dfs(1, 0);

    for (int i = 1; i <= n; i++)
    {
        lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y, c; cin>>x>>y>>c;

        

    }

    return 0;
}
