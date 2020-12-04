#include <bits/stdc++.h>
using namespace std;

const int MAXN = 35;
int n, m, k;
int dp[MAXN][MAXN][MAXN], ans = 0;

void dfs(int lef)
{
    if (!lef)
    {
        ++ans; return;
    }
    for (int i = 1; i <= lef; i++)
    {
        if ((i - m) % k)
        {
            if (dp[lef - i][m][k] != -1)
            {
                ans += dp[lef - i][m][k];
            }
            else
            {
                int res = ans;
                dfs(lef - i);
                dp[lef - i][m][k] = ans - res;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);

    int t; cin >> t;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m >> k;
        
        ans = 0;
        dfs(n);

        cout << ans << "\n";
    }    
    return 0;
}