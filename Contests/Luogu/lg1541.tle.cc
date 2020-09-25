#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e2 + 5;
int n, m;
int path[MAXN], meth[MAXN], vis[MAXN];
int ans = 0;

void dfs(int now, int sco)
{
    if (now == n)
    {
        ans = max(ans, sco);
        return;
    }
    
    for (int i = 1; i <= m; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            
            int nex = now + meth[i];
            dfs(nex, sco + path[nex]);
            
            vis[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        cin>>path[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin>>meth[i];
    }
    
    dfs(1, path[1]);
    
    cout<<ans<<endl;
    
    return 0;
}

