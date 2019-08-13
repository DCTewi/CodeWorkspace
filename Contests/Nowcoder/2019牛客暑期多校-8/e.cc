// WA
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
const ll INF = 1e10 + 5;

int n, m;

struct Edge
{
    int to;
    int next;
    ll l, r;
    Edge(int t = 0, int n = 0, ll L = 0, ll R = 0)
    {
        to = t; next = n; l = L; r = R;
    }
} edge[MAXN << 2] ;
ll head[MAXN];
void addedge(ll u, ll v, ll l, ll r)
{
    static int cnt = 0;
    cnt++;
    edge[cnt].to = v;
    edge[cnt].l = l;
    edge[cnt].r = r;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

ll dis[MAXN], vis[MAXN];
inline bool spfa(ll lim, bool isup)
{
#ifdef DEBUG
    cout << (isup? "up": "down") << "limit: " << lim << "\n";
#endif
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[1] = 0; vis[1] = 1;
    queue<ll> q; q.push(1);

    while (q.size())
    {
        ll u = q.front();
        for (int i = head[u]; i; i = edge[i].next)
        {
            ll v = edge[i].to;
            if (dis[v] > dis[u] + 1 && (isup? (lim <= edge[i].r): (lim >= edge[i].l)))
            {
                dis[v] = dis[u] + 1;
                if (!vis[v])
                {
                    q.push(v); vis[v] = 1;
                }
            }
        }
        q.pop(); vis[u] = 0;
    }

    if (dis[n] != dis[0])
    {
#ifdef DEBUG
        cout << "TRUE" << "\n";
#endif
        return true;
    }
    else return false;
}

ll maxs = -1, mins = INF;
int main()
{
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v; ll l, r;
        cin >> u >> v >> l >> r;
        addedge(u, v, l, r);
        addedge(v, u, l, r);
        maxs = max(max(l, r), maxs);
        mins = min(min(l, r), mins);
    }

    ll l = mins, r = maxs + 1, mid = 0, R = 0, L = 0;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (spfa(mid, true))
        {
            R = mid;
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    l = mins; r = maxs + 1;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (spfa(mid, false))
        {
            L = mid;
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    int ans = R - L + 1;
    (ans >= 0)? cout << ans << "\n": cout << "0\n";

    return 0;
}


