// A - Abandoned country 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
const int MAXM = 1e6 + 5;

ll n, m;

// (1)
struct Edge
{
    int p1, p2; ll cost;
    bool operator<(const Edge &other) const
	{
		return (*this).cost < other.cost;
	}
}edge[MAXM];
int father[MAXN];
ll mst = 0, cnt = 0;

int getf(int p)
{
    return father[p] == p? father[p]: father[p] = getf(father[p]);
}

inline void unite(int a, int b)
{
    father[getf(a)] = getf(b);
}

// (2)
vector<pair<int, ll>> g[MAXN];
int vis[MAXN];
ll ans = 0;

ll dfs(int s)
{
    vis[s] = 1;
    ll now = 0, sum = 1;
    for (auto &it : g[s])
    {
        if (!vis[it.first])
        {
            now = dfs(it.first);
            sum += now;
            ans += now * (n - now) * it.second;
        }
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
    {
        // Init & Input
        ans = mst = cnt = 0ll; memset(vis, 0, sizeof(vis));
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            father[i] = i; 
            g[i].clear();
        }
        for (int i = 1; i <= m; i++)
        {
            int u, v, cost;
            cin >> u >> v >> cost;
            edge[i].p1 = u; edge[i].p2 = v; edge[i].cost = cost;
        }

        // (1)
        sort(edge + 1, edge + 1 + m);
        cnt = n;
        for (int i = 1; i <= m; i++)
        {
            if (!n) break;
            int u = edge[i].p1, v = edge[i].p2;
            if (getf(u) != getf(v))
            {
                unite(u, v);
                mst += edge[i].cost;
                g[u].emplace_back(make_pair(v, edge[i].cost));
                g[v].emplace_back(make_pair(u, edge[i].cost));
                cnt--;
            }
        }
        cout << mst << " ";

        // (2)
        dfs(1);
        double res = (double)ans / ((double)n * (n - 1) / 2);
        cout << fixed << setprecision(2) << res << "\n";
    }
    return 0;
}
