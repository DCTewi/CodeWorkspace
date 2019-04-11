#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e3 + 5;
int n, m;
int a[MAXN][MAXN];
int lef[MAXN][MAXN], up[MAXN][MAXN], f[MAXN][MAXN];
int ans = 0;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>n>>m;
    // left up to right down
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin>>a[i][j];
            if (!a[i][j])
            {
                lef[i][j] = lef[i][j - 1] + 1;
                up[i][j] = up[i - 1][j] + 1;
            }
            
            if (a[i][j])
            {
                f[i][j] = min(f[i - 1][j - 1], min(lef[i][j - 1], up[i - 1][j])) + 1;
                ans = max(ans, f[i][j]);
            }
        }
    }
    
    // right up to left down
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            if (!a[i][j])
            {
                lef[i][j] = lef[i][j + 1] + 1;
                up[i][j] = up[i - 1][j] + 1;
            }
            
            if (a[i][j])
            {
                f[i][j] = min(f[i - 1][j + 1], min(lef[i][j + 1], up[i - 1][j])) + 1;
                ans = max(ans, f[i][j]);
            }
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}
