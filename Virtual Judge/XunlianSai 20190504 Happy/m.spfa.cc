#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

vector<int> edge[MAXN];
int n;
int path[MAXN], dis[MAXN], vis[MAXN], last[MAXN];

inline void add_edge(int u, int v)
{
    edge[u].emplace_back(v);
}

void spfa(int s)
{
    memset(dis, 0x3f, sizeof(dis)); dis[s] = 0;
    queue<int> q; q.push(s); vis[s] = 1;

    while (q.size())
    {
        int u = q.front();

        for (auto &v : edge[u])
        {
            if (dis[v] > dis[u] + 1)
            {
                dis[v] = dis[u] + 1;
                if (!vis[v])
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }

        q.pop(); vis[u] = 0;
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> path[i];
        add_edge(i - 1, i);
        if (last[path[i]])
        {
            add_edge(last[path[i]], i);
        }
        last[path[i]] = i;
    }

    spfa(1);

    cout << dis[n] << "\n";

    return 0;
}