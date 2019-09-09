#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int n, m;

vector<int> edges[MAXN], p;
int vis[MAXN];

template <class T> T read()
{
    T x = 0; int ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

inline void addedge(int u, int v)
{
    edges[u].emplace_back(v);
    edges[v].emplace_back(u);
}

int main()
{
    n = read<int>(), m = read<int>();
    for (int i = 0; i < m; i++)
    {
        int u = read<int>(), v = read<int>();
        if (!vis[u])
        {
            vis[u] = 1; p.emplace_back(u);
        }
        if (!vis[v])
        {
            vis[v] = 1; p.emplace_back(v);
        }
        addedge(u, v);
    }

    int ans = 0;
    for (auto u : p)
    {
        if (!vis[u]) continue;
        int flag = 0;

        queue<int> q; q.push(u);
        while (q.size())
        {
            int U = q.front(); vis[U] = 0; q.pop();
            int len = edges[U].size();
            for (int i = 0; i < len; i++)
            {
                int &v = edges[U][i];
                if (vis[v])
                {
                    flag = 1;
                    q.push(v);
                }
            }
        }
        if (flag) ans++;
    }

    printf("%d\n", ans);

    return 0;
}
