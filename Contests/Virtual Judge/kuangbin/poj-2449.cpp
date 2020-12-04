#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <deque>
#include <bitset>
using namespace std;
typedef long long ll;

const int MAXN = 1e3 + 5;
const int MAXM = 1e5 + 5;
const int MAXK = 1e3 + 5;
const int INF = 1 << 30;

struct Edge
{
    int v, w, next;
    Edge(int v = 0, int w = 0, int next = 0) : v(v), w(w), next(next) { }
} edge[MAXM << 2];
int headf[MAXN], headb[MAXN], edgecnt = 0;

void addedge(int u, int v, int w)
{
    edge[++edgecnt] = Edge(v, w, headf[u]); headf[u] = edgecnt;
    edge[++edgecnt] = Edge(u, w, headb[v]); headb[v] = edgecnt;
}

int dis[MAXN], vis[MAXN], ans[MAXK];
int n, m, s, t, k;

struct State
{
    int u, cost, sum;
    bool operator<(const State &o) const
    {
        return sum == o.sum ? cost > o.cost : sum > o.sum;
    }
    State(int u = 0, int g = 0) : u(u), cost(g)
    {
        sum = g + dis[u];
    }
};

void astar()
{
    if (dis[s] == INF) return;
    if (s == t) k++;
    int cnt = 0;

    priority_queue<State> q;
    q.push(State(s, 0));

    while (q.size())
    {
        State e = q.top(); q.pop();
        if (e.u == t)
        {
            ans[++cnt] = e.cost;
            if (cnt == k) return;
        }
        for (int i = headf[e.u]; i; i = edge[i].next)
        {
            q.push(State(edge[i].v, e.cost + edge[i].w));
        }
    }
}

void spfa()
{
    queue<int> q;
    q.push(t); vis[t] = 1; dis[t] = 0;
    while (q.size())
    {
        int u = q.front(); q.pop();
        for (int i = headb[u]; i; i = edge[i].next)
        {
            int v = edge[i].v;
            if (dis[v] > dis[u] + edge[i].w)
            {
                dis[v] = dis[u] + edge[i].w;
                if (!vis[v])
                {
                    q.push(v); vis[v] = 1;
                }
            }
        }
        vis[u] = 0;
    }
}

void init()
{
    memset(headb, 0, sizeof headb);
    memset(headf, 0, sizeof headf);
    memset(ans, -1, sizeof ans);
    memset(vis, 0, sizeof vis);
    for (int i = 0; i <= n; i++) dis[i] = INF;
    edgecnt = 0;
}

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        init();
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addedge(u, v, w);
        }
        scanf("%d%d%d", &s, &t, &k);

        spfa();
        astar();

        printf("%d\n", ans[k]);
    }
}
