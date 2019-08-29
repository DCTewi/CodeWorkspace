#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int read()
{
    int x = 0; char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}
vector<int> edge[7];
int vis[7], ans = 0;
void dfs(int p, int now)
{
    ans = max(ans, now);

    for (int i = 0; i < (int)edge[p].size(); i++)
    {
        if (!vis[edge[p][i]])
        {
            vis[edge[p][i]] = 1;

            dfs(edge[p][i], now + 1);
            vis[edge[p][i]] = 0;
        }
    }
}

int main()
{
    int T = read();
    while (T--)
    {
        for (int i = 0; i < 7; i++) edge[i].clear();
        memset(vis, 0, sizeof(vis));
        int maxl = 0, maxid = 0, maxn = 0; ans = 0;
        for (int i = 1; i < 6; i++)
        {
            int x = read(), y = read();
            edge[x].emplace_back(y);
            edge[y].emplace_back(x);
            if (maxl < (int)edge[x].size()) maxl = edge[x].size(), maxid = x, maxn = 0;
            if (maxl < (int)edge[y].size()) maxl = edge[y].size(), maxid = y, maxn = 0;
            if (maxl == (int)edge[x].size()) maxn++;
            if (maxl == (int)edge[y].size()) maxn++;
        }

        if (maxl <= 2) puts("n-hexane");
        else if (maxl >= 4) puts("2,2-dimethylbutane");
        else if (maxn >= 2) puts("2,3-dimethylbutane");
        else
        {
            vis[maxid] = 1;
            dfs(maxid, 0);
            if (ans >= 3) puts("2-methylpentane");
            else puts("3-methylpentane");
        }
    }

    return 0;
}
