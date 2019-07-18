#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e4 + 5;
const int MAXM = 1e5 + 5;
int n, m;

int father[MAXN], enemy[MAXN];
int getf(int p)
{
    return father[p] == p? p: father[p] = getf(father[p]);
}
void unit(int u, int v)
{
    father[getf(u)] = getf(v);
}

struct Edge
{
    int u, v, cost;
    Edge(int p = 0, int q = 0, int w = 0)
    {
        u = p, v = q, cost = w;
    }
};
vector<Edge> edges;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        edges.emplace_back(Edge(u, v, cost));
    }
    for (int i = 0; i <= n; i++)
    {
        father[i] = i;
    }

    sort(edges.begin(), edges.end(), [](Edge a, Edge b)->bool
    {
        return a.cost > b.cost;
    });

    for (auto &e : edges)
    {
        int &u = e.u, &v = e.v;
        if (getf(u) == getf(v))
        {
            cout << e.cost << "\n";
            return 0;
        }
        else
        {
            if (!enemy[v]) enemy[v] = u;
            else unit(enemy[v], u);

            if (!enemy[u]) enemy[u] = v;
            else unit(enemy[u], v);
        }
    }
    cout << "0\n";

    return 0;
}
