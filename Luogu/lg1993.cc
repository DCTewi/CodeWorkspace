#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
const int INF = 1 << 30;
int n, m;

struct Edge
{
    int to, cost, next;
} edge[MAXN << 2];
int head[MAXN << 2];

void add_edge(int u, int v, int w)
{
    static int cnt = 0;
    cnt++;
    edge[cnt].to = v;
    edge[cnt].cost = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

int vis[MAXN], dis[MAXN], flag = 0;
void spfa(int u)
{
    if (flag) return;
    vis[u] = 1;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to, w = edge[i].cost;
        if (dis[v] < dis[u] + w)
        {
            if (vis[v] || flag)
            {
                flag = 1; break;
            }
            dis[v] = dis[u] + w;
            spfa(v);
        }
    }
    vis[u] = 0;
}

int main()
{
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int opt, a, b, c;
        cin >> opt >> a >> b;
        switch (opt)
        {
            case 1:
            {
                cin >> c;
                add_edge(b, a, c);
                break;
            }
            case 2:
            {
                cin >> c;
                add_edge(a, b, -c);
                break;
            }
            case 3:
            {
                add_edge(a, b, 0);
                add_edge(b, a, 0);
                break;
            }
            default: break;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        add_edge(0, i, 0);
        dis[i] = -INF;
    }

    spfa(0); 
    cout << ((flag)? "No\n": "Yes\n");

    return 0;
}
