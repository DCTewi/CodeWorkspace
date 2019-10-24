#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 5;

int n, m;
int a[MAXN][MAXN], f[MAXN][MAXN];
int ans = 0;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin>>a[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j])
            {
                f[i][j] = min(min(f[i - 1][j - 1], f[i - 1][j]), f[i][j - 1]) + 1;
                ans = max(ans, f[i][j]);
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}
