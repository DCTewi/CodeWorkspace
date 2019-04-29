#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e2 + 5;
const int MAXQ = 5e4 + 5;

int n, m;
int t[MAXN], edge[MAXN][MAXN];

inline void add_edge(int u, int v, int cost)
{
    edge[u][v] = edge[v][u] = cost;
}

inline void floyd(int k)
{
    for (int u = 0; u < n; u++)
    {
        for (int v = 0; v < n; v++)
        {
            if (edge[u][v] > edge[u][k] + edge[k][v])
            {
                edge[u][v] = edge[u][k] + edge[k][v];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    memset(edge, 0x3f, sizeof(edge));
    const int INF = edge[MAXN - 1][MAXN - 1];

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        add_edge(u, v, w);
    }

    int Q, now = 0; cin >> Q;
    while (Q--)
    {
        int x, y, T; cin >> x >> y >> T;
        for (; t[now] <= T && now < n; now++)
        {
            floyd(now);
        }
        if ((t[x] > T || t[y] > T) || edge[x][y] == INF)
        {
            cout << "-1\n";
        }
        else
        {
            cout << edge[x][y] << "\n";
        }
    }

    return 0;
}
