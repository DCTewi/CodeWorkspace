#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

map<int, int> hunter, victim;
int n, k, ans = 0;
int fa[MAXN];

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
    cin >> n >> k;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= k; i++)
    {
        int opt, x, y; cin >> opt >> x >> y;
        if (x > n || y > n)
        {
            ans++;
        }
        else if (opt == 1)
        {
            unite(x, y);
        }
        else
        {
            int u = getfa(x), v = getfa(y);
            if (u == v)
            {
                ans++;
            }
            else if (hunter.count(u) && hunter[u] != v)
            {
                ans++;
            }
            else if (victim.count(v) && victim[v] != u)
            {
                ans++;
            }
            else
            {
                hunter[u] = v; victim[v] = u;
            }
            
        }
    }

    cout << ans << "\n";

    return 0;
}
