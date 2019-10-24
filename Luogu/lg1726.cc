#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e3 + 5;
const int MAXM = 5e4 + 5;
int n, m;
priority_queue<int, vector<int>, greater<int>> path;

struct Edge
{
    int to, next;
} edge[MAXM << 2] ;
int head[MAXN];
void add_edge(int u, int v)
{
    static int cnt = 0;
    cnt++;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

int low[MAXN], dfn[MAXN], vis[MAXN], ind = 0;
stack<int> q;
void tarjan(int u)
{
    low[u] = dfn[u] = ++ind;
    q.push(u); vis[u] = 1;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (vis[v])
        {
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == dfn[u])
    {
        priority_queue<int, vector<int>, greater<int>> now;
        while (q.top() != u)
        {
            now.push(q.top());
            vis[q.top()] = 0;
            q.pop();
        }
        q.pop(); now.push(u); vis[u] = 0;
        if (now.size() > path.size())
        {
            swap(now, path);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, t;
        cin >> u >> v >> t;
        add_edge(u, v);
        if (t == 2) add_edge(v, u);
    }

    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);

    cout << path.size() << "\n";
    while (path.size())
    {
        cout << path.top() << " \n"[path.size() == 1];
        path.pop();
    }

    return 0;
}
