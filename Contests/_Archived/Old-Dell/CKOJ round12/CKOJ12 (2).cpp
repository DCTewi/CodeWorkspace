#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 15;
bool vis[MAXN];
int n, ring[MAXN];
ll a[MAXN];

inline bool ismulti(ll a, ll base)
{
    if (base == 0)
    {
        if (a == 0) return true;
        else return false;
    }
    if (!(a % base)) return true;
    return false;
}

bool dfs(int index)
{
    if (index > n)
    {
        return false;
    }
    if (index == n)
    {
        if (ismulti(ring[n - 2] + ring[0], ring[n - 1]) && ismulti(ring[1] + ring[n - 1], ring[0]))
        {
            return true;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && (index < 2 || ismulti(ring[index - 2] + a[i], ring[index - 1])))
        {
            vis[i] = true;
            ring[index] = a[i];
            #ifdef TEWILOCAL
            cout<<ring[index]<<" "<<index<<" "<<i<<endl;
            #endif // TEWILOCAL
            if (dfs(index + 1)) return true;
            vis[i] = false;
        }
    }
    return false;
}

int main()
{
    int T;cin>>T;
    while(T--)
    {
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
        }
        memset(vis, 0, sizeof(vis));
        memset(ring, 0, sizeof(ring));
        dfs(0)?printf("Yes\n"):printf("No\n");
    }

    return 0;
}
