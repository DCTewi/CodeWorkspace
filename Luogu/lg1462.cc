#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e4 + 5;
const int MAXM = 5e4 + 5;
const ll INF = 1e10 + 5;

struct Edge
{
    ll to, cost;

    Edge(ll t = 0LL, ll c = 0LL)
    {
        this->to = t; this->cost = c;
    }
};
ll n, m, hp;
vector<Edge> edge[MAXN];
ll fee[MAXN], f_range[MAXN], dis[MAXN], vis[MAXN];

inline void add_edge(ll u, ll v, ll cost)
{
    edge[u].push_back(Edge(v, cost));
    edge[v].push_back(Edge(u, cost));
}

inline void init()
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[1] = 0;
}

inline bool spfa(ll uplimit)
{
    init();
    queue<ll> q; q.push(1); vis[1] = 1;

    while (q.size())
    {
        ll u = q.front();

        for (auto &it : edge[u])
        {
            ll v = it.to, w = it.cost;
            if (dis[v] > dis[u] + w && fee[v] <= uplimit)
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

    if (dis[n] <= hp)
    {
        return true;
    }
    else return false;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> hp;
    for (int i = 1; i <= n; i++)
    {
        cin >> fee[i];
        f_range[i] = fee[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        add_edge(u, v, w);
    }

    if (!spfa(INF))
    {
        return 0 * puts("AFK");
    }

    sort(f_range + 1, f_range + 1 + n, [](ll a, ll b)->bool
    {
        return a < b;
    });

    ll l = 1, r = n, mid, ans = 0;

    while (l <= r)
    {
        mid = (l + r) / 2;
        if (spfa(f_range[mid]))
        {
            ans = f_range[mid];
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout<<ans<<"\n";

    return 0;
}