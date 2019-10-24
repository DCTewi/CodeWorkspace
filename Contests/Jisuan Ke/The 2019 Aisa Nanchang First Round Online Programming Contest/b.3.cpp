#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1E3 + 5;

ll v, e, s, k, c;

template <class T> T read()
{
    T x = 0; int ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

struct Graph
{
    struct Edge
    {
        ll to, cost;
        Edge (ll t = 0, ll c = 0)
        {
            to = t, cost = c;
        }
    };
    vector<Edge> edge[MAXN];
    void addedge(ll u, ll v, ll w)
    {
        edge[u].emplace_back(Edge(v, w));
    }

    ll vis[MAXN], dis[MAXN];

    ll spfa(ll start)
    {
        memset(vis, 0, sizeof(vis));
        memset(dis, 0x3f, sizeof(dis));
        queue<ll> q; q.push(start);
        vis[start] = 1; dis[start] = 0;
        while (q.size())
        {
            ll u = q.front();
            for (auto it : edge[u])
            {
                ll v = it.to, w = it.cost;
                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    if (!vis[v])
                    {
                        vis[v] = 1; q.push(v);
                    }
                }
            }
            q.pop(); vis[u] = 0;
        }

        sort(dis + 1, dis + 1 + v);
        return dis[v];
    }
};

int main()
{
    int T = read<int>();
    while (T--)
    {
        v = read<ll>(); e = read<ll>(); s = read<ll>(); k = read<ll>(); c = read<ll>();

        vector<ll> team(k);
        Graph g;

        for (ll i = 0; i < k; i++)
        {
            team[i] = read<ll>();
        }
        for (ll i = 0; i < e; i++)
        {
            ll u = read<ll>(), v = read<ll>(), w = read<ll>();
            g.addedge(u, v, w);
            g.addedge(v, u, w);
        }

        ll hero = g.spfa(s), teamans = 0;
        for (ll i = 0; i < k; i++)
        {
            teamans = max(teamans, g.spfa(team[i]));
        }

        if (hero <= teamans * c)
        {
            printf("%I64d\n", hero);
        }
        else
        {
            printf("%I64d\n", teamans);
        }
    }
    return 0;
}
