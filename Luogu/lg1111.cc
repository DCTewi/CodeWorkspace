#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
struct Edge
{
    int u, v, w;
    Edge (int u = 0, int v = 0, int w = 0)
    {
        this->u = u; this->v = v; this->w = w;
    }
};

vector<Edge> edge;
int fa[MAXN];
int n, m;
int cnt = 0;

int getfa(int u)
{
    return fa[u] == u? u: fa[u] = getfa(fa[u]);
}

void unite(int u, int v)
{
    fa[getfa(u)] = getfa(v);
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> m; cnt = n;
    for (int i = 1; i <= n; i++) fa[i] = i;

    for (int i = 0; i < m; i++)
    {
        int x, y, t; cin >> x >> y >> t;
        edge.emplace_back(Edge(x, y, t));
    }

    sort(edge.begin(), edge.end(), [](Edge a, Edge b)->bool
    {
        return a.w < b.w;
    });

    for (Edge e : edge)
    {
        int u = e.u, v = e.v;
        if (getfa(u) != getfa(v))
        {
            cnt--;
            unite(u, v);
        }
        if (cnt <= 1)
        {
            cout << e.w << "\n";
            return 0;
        }
    }

    cout << "-1\n";

    return 0;
}
