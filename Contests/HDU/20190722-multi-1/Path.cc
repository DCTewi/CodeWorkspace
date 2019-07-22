// TLE

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e4 + 5;

ll n, m;
struct Edge
{
    ll to, cost, deled = 0;
    Edge(ll v = 0, ll w = 0)
    {
        to = v; cost = w; deled = 0;
    }
};
vector<Edge> edge[MAXN];

ll minpath = -1, ans = 0;
ll dis[MAXN], vis[MAXN], pre[MAXN], len[MAXN];
bool spfa(int s)
{
    queue<int> q;
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    memset(pre, 0, sizeof(pre));
    memset(len, 0, sizeof(len));

    q.push(s); vis[s] = 1; dis[s] = 0;

    while (q.size())
    {
        int u = q.front();

        for (auto &x : edge[u])
        {
            int v = x.to;
            if (!x.deled && dis[v] > dis[u] + x.cost)
            {
                dis[v] = dis[u] + x.cost;
                pre[v] = u; len[v] = x.cost;
                if (!vis[v])
                {
                    q.push(v); vis[v] = 1;
                }
            }
        }
        vis[u] = 0; q.pop();
    }
    
    // cout << dis[n] << "-" << pre[n] << " "<< minpath << endl;

    if (dis[n] == dis[0]) return true;

    if (minpath == -1)
    {
        minpath = dis[n];
    }
    else if (minpath != dis[n]) return true;

    int minedge = 1 << 30, x = 0;
    for (int u = n; u != s; u = pre[u])
    {
        if (len[u] < minedge)
        {
            minedge = len[u]; x = pre[u];
        }
    }
    // cout << "edge[" << x << ", " << y << "] deled with " << minedge << "\n"; 
    for (auto &it : edge[x])
    {
        if (it.cost == minedge)
        {
            it.deled = 1; break;
        }
    }
    ans += minedge;

    return false;
}

void init()
{
    minpath = -1, ans = 0;
    for (int i = 0; i <= n; i++)
    {
        edge[i].clear();
    }
}

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%lld%lld", &n, &m);
        init();
        for (int i = 1; i <= m; i++)
        {
            int u, v, w; scanf("%d%d%d", &u, &v, &w);
            edge[u].emplace_back(Edge(v, w));
        }

        while (!spfa(1));

        printf("%lld\n", ans);
    }

    return 0;
}
