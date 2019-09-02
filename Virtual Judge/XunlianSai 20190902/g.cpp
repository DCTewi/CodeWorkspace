#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 55;

int n, p;
vector<int> edge[MAXN];
set<int> py[MAXN];

void addedge(int u, int v)
{
    edge[u].emplace_back(v);
    py[u].insert(v);    
}

int read()
{
    int x = 0, ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{
    n = read(), p = read();

    for (int i = 1; i <= n; i++)
    {
        int num = read();
        for (int j = 0; j < num; j++)
        {
            int v = read();
            addedge(i , v);
        }
    }
    vector<int> ans;
    for (int u : edge[p])
    {
        for (int v : edge[u])
        {
            if (v != p && py[v].count(p) == 0)
            {
                ans.emplace_back(v);
            }
        }
    }
    sort(ans.begin(), ans.end());
    auto it = unique(ans.begin(), ans.end());
    printf("%d\n", it - ans.begin());
    for (auto i = ans.begin(); i != it; i++)
    {
        printf("%d ", *i);
    }
    if (it - ans.begin())puts("");

    return 0;
}
