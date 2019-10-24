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
int v, e, s, k, c;

struct Graph
{
    struct Edge
    {
        int to, next, cost;
        Edge(int t = 0, int c = 0, int n = 0)
        {
            to = t, next = n, cost = c;
        }
    };
    vector<Edge> edges;

    int head[MAXN << 2];
    int dis[MAXN], vis[MAXN];
    queue<int> q;

    Graph(int n)
    {
        memset(head, 0, sizeof(head));
        edges = vector<Edge>(1);
    }

    void addedge(int u, int v, int w)
    {
        edges.emplace_back(Edge(v, w, head[u]));
        head[u] = edges.size() - 1;
    }

    int spfa(int start)
    {
        memset(dis, 0x3f, sizeof(dis));
        memset(vis, 0, sizeof(vis));
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

        sort(dis + 1, dis + 1 + v);
        return dis[v];
    }
};

int main()
{
    int T = read<int>();
    while (T--)
    {
        v = read<int>(), e = read<int>(), s = read<int>(), k = read<int>(), c = read<int>();
        vector<int> team(k);
        for (int i = 0; i < k; i++)
        {
            team[i] = read<int>();
        }
        Graph g(v);
        for (int i = 0; i < e; i++)
        {
            int u = read<int>(), v = read<int>(), w = read<int>();
            g.addedge(u, v, w);
            g.addedge(v, u, w);
        }
        
        int hero = g.spfa(s), grou = -1;
        for (int i : team)
        {
            grou = max(grou, g.spfa(i));
        }

        if (hero <= grou * c)
        {
            printf("%d\n", hero);
        }
        else
        {
            printf("%d\n", grou);
        }
    }

    return 0;
}

