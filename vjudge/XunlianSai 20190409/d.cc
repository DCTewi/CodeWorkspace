#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 5;
int line[MAX][MAX];
int used[MAX], vis[MAX];
int all = 0;

int n, m;

bool find(int x)
{
    for (int j = 0; j< m; j++)
    {
        if (line[x][j] && used[j] == false)
        {
            used[j] = 1;
            if (vis[j] == -1 || find(vis[j]))
            {
                vis[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    memset(vis, -1, sizeof(vis));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        line[u][v] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        memset(used, 0, sizeof(used));
        if (find(i)) all += 1;
    }

    if (all == n) puts("YES");
    else puts("NO");
    return 0;
}
