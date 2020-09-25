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

const int MAXN = 5e5 + 5;
int n, k;
set<int> wish, wishtree;
struct Graph
{
    struct Edge
    {
        int to, cost;
        Edge(int to, int cost) : to(to), cost(cost) {}
    };
    vector<Edge> edge[MAXN];

    void addedge(int u, int v, int w)
    {
        edge[u].emplace_back(Edge(v, w));
        edge[v].emplace_back(Edge(u, w));
    }
} gsum, gout;
int wishsize = 0;

int pre[MAXN], vis[MAXN], dis[MAXN];
void spfa(int s, const Graph &g)
{
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    queue<int> q; dis[s] = 0;
    vis[s] = 1; q.push(s);
    while (q.size())
    {
        int u = q.front();
        for (int i = 0; i < g.edge[u].size(); i++)
        {
            int v = g.edge[u][i].to, w = g.edge[u][i].cost;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                pre[v] = u;
                if (!vis[v])
                {
                    q.push(v); vis[v] = 1;
                }
            }
        }
        vis[u] = 0; q.pop();
    }
}

int father[MAXN];
int getfa(int p)
{
    return father[p] == p? p: father[p] = getfa(father[p]);
}
void unit(int u, int v)
{
    father[getfa(u)] = getfa(v);
}
void getwishsize()
{
    vector<tuple<int, int, int>> wishedge; int cnt = wishtree.size();
    for (int i = 1; i <= n; i++) father[i] = i;
    for (int u : wishtree)
    {
        for (auto &e : gsum.edge[u])
        {
            if (wishtree.count(e.to))
            {
                wishedge.emplace_back(make_tuple(e.cost, u, e.to));
            }
        }
    }
    sort(wishedge.begin(), wishedge.end());
    for (auto &e : wishedge)
    {
        if (!cnt) break;
        int u = get<1>(e), v = get<2>(e);
        if (getfa(u) != getfa(v))
        {
            unit(u, v);
            wishsize += get<0>(e);
            cnt--;
        }
    }
}

int main()
{
    n = read<int>(), k = read<int>();
    for (int i = 1; i < n; i++)
    {
        int u = read<int>(), v = read<int>(), w = read<int>();
        gsum.addedge(u, v, w);
    }
    for (int i = 0; i < k; i++)
    {
        int p = read<int>();
        wish.insert(p);
    }
    wishtree = wish;

    spfa(*wish.begin(), gsum);
    for (auto i = wish.begin(); i != wish.end(); i++)
    {
        int now = *i;
        while (pre[now] && pre[now] != (*wish.begin()) && wishtree.count(pre[now]) == 0)
        {
            wishtree.insert(pre[now]); now = pre[now];
        }
    }
    getwishsize();

    for (int u = 1; u <= n; u++)
    {
        if (wishtree.count(u))
        {
            for (int i = 0; i < gsum.edge[u].size(); i++)
            {
                int v = gsum.edge[u][i].to, w = gsum.edge[u][i].cost;
                if (wishtree.count(v)) continue;
                gout.addedge(0, v, w);
            }
        }
        else
        {
            for (int i = 0; i < gsum.edge[u].size(); i++)
            {
                int v = gsum.edge[u][i].to, w = gsum.edge[u][i].cost;
                if (wishtree.count(v)) gout.addedge(u, 0, w);
                else gout.addedge(u, v, w);
            }
        }
    }

    spfa(0, gout);

    for (int i = 1; i <= n; i++)
    {
        if (wishtree.count(i))
        {
            printf("%d\n", wishsize);
        }
        else
        {
            printf("%d\n", wishsize + dis[i]);
        }
    }

    return 0;
}
/**
6 2
1 2 1
2 3 2
2 5 3
3 4 4
3 6 5
5
6

*/