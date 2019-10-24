#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 305;
const int MAXM = 505;

template <class T>
T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w? -x: x;
}

struct Edge
{
    int to;
    ll cost;
    int next;
    
    Edge(int t = 0, ll c = 0, int ne = 0)
    {
        to = t; cost = c; next = ne;
    }
};

struct Spfa
{
    vector<int> head;
    queue<int> q;
    vector<Edge> edges;
    ll dis[MAXN];
    int vis[MAXN];

    Spfa(int maxn)
    {
        head = vector<int>(maxn, 0);
        edges = vector<Edge>(1);
    }

    void addedge(int u, int v, ll w)
    {
        edges.emplace_back(Edge(v, w, head[u]));
        head[u] = edges.size() - 1;
    }

    ll run(int start, int fin)
    {
        memset(vis, 0, sizeof(vis));
        memset(dis, 0x3f, sizeof(dis));

        dis[start] = 0; vis[start] = 1; q.push(start);

        while (q.size())
        {
            int u = q.front();
            for (int i = head[u]; i; i = edges[i].next)
            {
                int v = edges[i].to, w = edges[i].cost;
                if (dis[v] > dis[u] + w)
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
        
        return dis[fin];
    }
};

int main()
{
    int T = read<int>();
    while (T--)
    {
        int n = read<int>(), m = read<int>();
        Spfa spfa(n);

        for (int i = 0; i < m; i++)
        {
            int u = read<int>(), v = read<int>(); ll w = read<ll>();
            spfa.addedge(u, v, w);
        }

        for (int i = 0; i < 6; i++)
        {
            int x = read<int>(), y = read<int>();

            ll now = spfa.run(y, x);

            spfa.addedge(x, y, -now);
            printf("%I64d\n", -now);
        }
    }
    return 0;
}

