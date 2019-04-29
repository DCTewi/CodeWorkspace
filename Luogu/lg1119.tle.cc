// TLE 80
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e2 + 5;
const int MAXQ = 5e4 + 5;

struct Edge
{
    int to, cost;

    Edge (int t = 0, int c = 0)
    {
        this->to = t; this->cost = c;
    }
};
vector<Edge> edge[MAXN];
int n, m;
int t[MAXN], dis[MAXN], vis[MAXN];

inline void init()
{
    memset(dis, -1, sizeof(dis));
    memset(vis, 0, sizeof(vis));
}

inline void add_edge(int u, int v, int cost)
{
    edge[u].push_back(Edge(v, cost));
    edge[v].push_back(Edge(u, cost));
}

inline int spfa(int s, int e, int time)
{
    if (t[s] > time || t[e] > time) return -1;

    init(); dis[s] = 0;
    queue<int> q; q.push(s); vis[s] = 1;

    while (q.size())
    {
        int u = q.front();
        for (auto &it : edge[u])
        {
            int v = it.to, w = it.cost;
            if ((dis[v] == -1 || dis[v] > dis[u] + w) && t[v] <= time)
            {
                dis[v] = dis[u] + w;
                if (!vis[v])
                {
                    q.push(v); vis[v] = 1;
                }
            }
        }
        q.pop(); vis[u] = 0;
    }

    return dis[e];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

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

    int Q; cin >> Q;
    while (Q--)
    {
        int x, y, T; cin >> x >> y >> T;
        cout << spfa(x, y, T) << "\n";
    }

    return 0;
}
