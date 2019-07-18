// TLE
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e3 + 5;
const int MAXM = 5e4 + 5;
int n, m, ans = 0;
unordered_map<int, bool> edges[MAXN];
priority_queue<int, vector<int>, greater<int>> path;
int vis[MAXN];

void bfs(int s)
{
    memset(vis, 0, sizeof(vis));
    int res = 1; queue<int> q;
    priority_queue<int, vector<int>, greater<int>> pathnow;
    q.push(s); vis[s] = 1; pathnow.push(s);
    while (q.size())
    {
        int u = q.front();
        for (auto &it : edges[u])
        {
            int v = it.first;
            if (!vis[v] && edges[v].count(u))
            {
                vis[v] = 1; q.push(v);
                pathnow.push(v);
                res++;
            }
        }
        q.pop();
    }
    if (res > ans)
    {
        swap(path, pathnow);
        ans = res;
    }
}

int main()
{
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int type, u, v;
        cin >> u >> v >> type;
        edges[u][v] = 1;
        if (type == 2) edges[v][u] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        bfs(i);
    }

    cout << ans << "\n";
    while (path.size())
    {
        cout << path.top() << " \n"[path.size() == 1];
        path.pop();
    }

    return 0;
}
