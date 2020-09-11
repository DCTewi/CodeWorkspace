#include <bits/stdc++.h>
using namespace std;

const int MAXC = 7e3 + 5;
const int MAXN = 3e3 + 5;
struct Edge
{
    int to, cost;

    Edge(int t = 0, int c = 0)
    {
        this->to = t; this->cost = c;
    }
};
int t, c, s, e;
vector<Edge> edge[MAXN];
int vis[MAXN], dis[MAXN];

void add_edge(int &u, int &v, int &cost)
{
    edge[u].push_back(Edge(v, cost));
    edge[v].push_back(Edge(u, cost));
}

void spfa()
{
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    queue<int> q; q.push(s); vis[s] = 1;

    while (q.size())
    {
        int u = q.front();
        for (auto &e : edge[u])
        {
            int v = e.to;
            if (dis[v] > dis[u] + e.cost)
            {
                dis[v] = dis[u] + e.cost;
                if (!vis[v])
                {
                    q.push(v); vis[v] = 1;
                }
            }
        }
        q.pop(); vis[u] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);

    cin>>t>>c>>s>>e;
    for (int i = 0; i < c; i++)
    {
        int u, v, c; cin>>u>>v>>c;
        add_edge(u, v, c);
    }

    spfa();

    cout<<dis[e]<<"\n";

    return 0;
}