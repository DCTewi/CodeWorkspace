#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e4 + 5;
const int lMAXM = 1e6 + 5;
int n, m;

struct Edge
{
    int to, cost;
    Edge(int t = 0, int c = 0)
    {
        to = t; cost = c;
    }
};
vector<Edge> g[MAXN];
struct Edge_d
{
    int u, v, cost;
    Edge_d(int i = 0, int j = 0, int c = 0)
    {
        u = i; v = j; cost = c;
    }
};
vector<Edge_d> edge;

int vis[MAXN];

int main()
{
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        edge.emplace_back(Edge_d(u, v, cost));
        g[u].emplace_back(Edge(v, cost));
        g[v].emplace_back(Edge(u, cost));
    }
    sort(edge.begin(), edge.end(), [](Edge_d a, Edge_d b)->bool
    {
        return a.cost > b.cost;
    });

    for (auto &i : edge)
    {
        int minres = 1 << 30, u = i.u, v = i.v;
        bool a = true, b = true;
        for (auto &it : g[u])
        {
            if (vis[it.to]) minres = min(minres, it.cost);
            if (vis[it.to] == 1)
            {
                a = false;
            }
            else if (vis[it.to] == 2)
            {
                b = false;
            }
        }
        if (a) vis[u] = 1;
        else if (b) vis[u] = 1;
    }

    return 0;
}
