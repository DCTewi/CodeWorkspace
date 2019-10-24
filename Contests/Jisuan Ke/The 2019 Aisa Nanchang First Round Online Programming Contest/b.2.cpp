#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e3 + 5;

template <class T> T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w? -x: x;
}
ll v, e, s, k, c;

struct Graph
{
    struct Edge
    {
        ll to, cost;
        Edge(ll t = 0, ll c = 0)
        {
            to = t, cost = c;
        }
    };
    vector<Edge> edge[MAXN];
    ll dis[MAXN], vis[MAXN];
    queue<ll> q;

    Graph(ll n)
    {
    }

    void addedge(ll u, ll v, ll w)
    {
        edge[u].emplace_back(Edge(v, w));
    }

    ll spfa(ll start)
    {
        memset(dis, 0x3f, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        dis[start] = 0; vis[start] = 1; q.push(start);

        vector<ll> res(v + 1, 0);

        while (q.size())
        {
            ll u = q.front();
            for (auto it : edge[u])
            {
                ll &v = it.to, &w = it.cost;
                if (dis[v] > dis[u] + w)
                {
                    res[v] = w;
                    dis[v] = dis[u] + w;
                    if (!vis[v])
                    {
                        q.push(v); vis[v] = 1;
                    }
                }
            }
            q.pop(); vis[u] = 0;
        }

        sort(res.begin(), res.end());
        return res[res.size() - 1];
    }
};

int main()
{
    int T = read<int>();
    while (T--)
    {
        v = read<ll>(), e = read<ll>(), s = read<ll>(), k = read<ll>(), c = read<ll>();
        vector<ll> team(k);
        for (int i = 0; i < k; i++)
        {
            team[i] = read<ll>();
        }
        Graph g(v);
        for (int i = 0; i < e; i++)
        {
            ll u = read<ll>(), v = read<ll>(), w = read<ll>();
            g.addedge(u, v, w);
            g.addedge(v, u, w);
        }
        
        ll hero = g.spfa(s), grou = -1;
        for (ll i : team)
        {
            grou = max(grou, g.spfa(i));
        }

        if (hero <= grou * c)
        {
            printf("%I64d\n", hero);
        }
        else
        {
            printf("%I64d\n", grou);
        }
    }

    return 0;
}
