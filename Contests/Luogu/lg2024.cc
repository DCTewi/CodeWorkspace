#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int n, m, ans = 0;
int fa[MAXN * 3];

int getfa(int p)
{
    return fa[p] == p? p: fa[p] = getfa(fa[p]);
}

void unite(int u, int v)
{
    fa[getfa(u)] = getfa(v);
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n * 3; i++) fa[i] = i;

    while (m--)
    {
        int opt, u, v;
        cin >> opt >> u >> v;
        if (u > n || v > n) 
        {
            ans++; continue;
        }
        if (opt == 1)
        {
            if (getfa(u + n) == getfa(v) || getfa(u) == getfa(v + n))
            {
                ans++;
            }
            else
            {
                unite(u, v); unite(u + n, v + n); unite(u + n + n, v + n + n);
            }            
        }
        else
        {
            if (getfa(u) == getfa(v) || getfa(u) == getfa(v + n))
            {
                ans++;
            }
            else
            {
                unite(u + n, v); unite(u + n + n, v + n); unite(u, v + n + n);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
