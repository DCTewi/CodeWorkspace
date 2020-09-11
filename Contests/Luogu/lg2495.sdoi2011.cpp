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

const int MAXN = 25e4 + 5;
const int LOGN = 31;

struct Edge
{
    int to; ll cost; int next;
    Edge(int to, ll cost, int next) : to(to), cost(cost), next(next) {}
};

struct Graph
{
    vector<Edge> edges;
    int head[MAXN];
    Graph()
    {
        memset(head, -1, sizeof(head));
    }
    void addedge(int u, int v, ll w)
    {
        edges.emplace_back(Edge(v, w, head[u]));
        head[u] = edges.size() - 1;
    }
} g, *vtr;

int dep[MAXN], dfn[MAXN], fa[MAXN][LOGN + 1];
ll len[MAXN][LOGN + 1];
void dfs(int now, int father)
{
    static int idx = 0;
    fa[now][0] = father; dep[now] = dep[father] + 1; dfn[now] = ++idx;
    for (int i = 1; i <= LOGN; i++)
    {
        fa[now][i] = fa[fa[now][i - 1]][i - 1];
        len[now][i] = min(len[now][i - 1], len[fa[now][i - 1]][i - 1]);
    }
    for (int i = g.head[now]; ~i; i = g.edges[i].next)
    {
        int v = g.edges[i].to;
        if (v != father)
        {
            len[v][0] = g.edges[i].cost;
            dfs(v, now);
        }
    }
}

int lca(int a, int b, ll &w)
{
    w = INT_MAX;
    if (dep[a] > dep[b]) swap(a, b);
    for (int i = LOGN; i >= 0; i--)
    {
        if (dep[fa[b][i]] >= dep[a])
        {
            w = min(w, len[b][i]); b = fa[b][i];
        }
    }
    if (a == b) return a;
    for (int i = LOGN; i >= 0; i--)
    {
        if (fa[a][i] != fa[b][i])
        {
            w = min({w, len[a][i], len[b][i]});
            a = fa[a][i], b = fa[b][i];
        }
    }
    return fa[a][0];
}

bool vis[MAXN];
vector<int> key;
inline void initkey()
{
    key.clear();
    memset(vis, 0, sizeof(vis));
}
int stk[MAXN], top = 0;
void makevtree()
{
    sort(key.begin(), key.end(), [](const int &a, const int &b)-> bool
    {
        return dfn[a] < dfn[b];
    });
    stk[top = 1] = 1; ll w = 0;

    for (int now : key)
    {
        if (now != 1)
        {
            int l = lca(now, stk[top], w);
            printf("%d-%d's lca=%d\n", now, stk[top], l);
            if (l != stk[top])
            {
                while (dfn[l] < dfn[stk[top - 1]])
                {
                    lca(stk[top - 1], stk[top], w);
                    vtr->addedge(stk[top - 1], stk[top], w);
                    top--;
                }
                if (dfn[l] > dfn[stk[top - 1]])
                {
                    lca(l, stk[top], w);
                    vtr->addedge(l, stk[top], w);
                    stk[top] = l; // <==> top--; stk[++top] = l;
                }
                else // lca == stk[top - 1]
                {
                    lca(l, stk[top], w);
                    vtr->addedge(l, stk[top], w); top--;
                }
            }
            stk[++top] = now;
        }
    }
    for (int i = 1; i < top; i++)
    {
        lca(stk[i], stk[i + 1], w);
        vtr->addedge(stk[i], stk[i + 1], w);
    }
}

ll f[MAXN];
void dp(int p)
{
    f[p] = 0;
    for (int i = vtr->head[p]; ~i; i = vtr->edges[i].next)
    {
        int v = vtr->edges[i].to; ll w = vtr->edges[i].cost;
        dp(v);
        if (vis[v])
        {
            f[i] += w;
        }
        else
        {
            f[i] += min(w, f[v]);
        }
    }
}

int n, m;
int main()
{
    n = read<int>(); cout << "n = " << n << "\n";
    for (int i = 1; i < n; i++)
    {
        int u = read<int>(), v = read<int>(), w = read<int>();
        g.addedge(u, v, w); g.addedge(v, u, w);
    }
    dfs(1, 0);

    m = read<int>();
    while (m--)
    {
        vtr = new Graph();
        initkey();

        int k = read<int>();
        for (int i = 0; i < k; i++)
        {
            int u = read<int>();
            vis[u] = 1; key.emplace_back(u);
        }

        makevtree(); dp(1);
        printf("%lld\n", f[1]);

        delete vtr;
    }

    return 0;
}
