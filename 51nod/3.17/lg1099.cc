#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#define eps 1e-5
#define MAXN 100005
#define MAXM 111111
#define INF 1000000007
using namespace std;
int n, m;
struct EDGE
{
    int v, next, w;
}edge[MAXN];
int head[MAXN], e;
int q[MAXN], vis[MAXN], d[MAXN];
void init()
{
    e = 0;
    memset(head, -1, sizeof(head));
}
void add(int u, int v, int w)
{
    edge[e].v = v;
    edge[e].w = w;
    edge[e].next = head[u];
    head[u] = e++;
}
void bfs(int src)
{
    for(int i = 1; i <= n; i++) vis[i] = 0, d[i] = INF;
    int h = 0, t = 0;
    q[t++] = src;
    vis[src] = 1;
    d[src] = 0;
    while(h < t)
    {
        int u = q[h++];
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            int w = edge[i].w;
            if(d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                if(!vis[v])
                {
                    q[t++] = v;
                    vis[v] = 1;
                }
            }
        }
    }
}
int main()
{
    int u, v, w;
    scanf("%d%d", &n, &m);
    init();
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d%d%*s", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    bfs(1);
    int pos = -1, mx = -1;
    for(int i = 1; i <= n; i++)
        if(d[i] > mx)
        {
            mx = d[i];
            pos = i;
        }
    bfs(pos);
    mx = -1;
    for(int i = 1; i <= n; i++)
        if(d[i] > mx) mx = d[i];
    printf("%d\n", mx);
    return 0;
}

