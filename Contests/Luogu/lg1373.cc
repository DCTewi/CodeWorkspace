#include <bits/stdc++.h>
using namespace std;

const int MAXN = 8e2 + 5;
const int MOD = 1e9 + 7;
int n, m, k = 0;
int ans = 0;
int a[MAXN][MAXN], f[MAXN][MAXN][20][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    k++;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            f[i][j][a[i][j] % k][0] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int h = 0; h < k; h++)
            {
                if (i < n)
                {
                    f[i + 1][j][(h + a[i + 1][j]) % k][0] = (f[i + 1][j][(h + a[i + 1][j]) % k][0] + f[i][j][h][1]) % MOD;
                    f[i + 1][j][(h - a[i + 1][j] + k) % k][1] = (f[i + 1][j][(h - a[i + 1][j] + k) % k][1] + f[i][j][h][0]) % MOD;
                }
                if (j < m)
                {
                    f[i][j + 1][(h + a[i][j + 1]) % k][0] = (f[i][j + 1][(h + a[i][j + 1]) % k][0] + f[i][j][h][1]) % MOD;
                    f[i][j + 1][(h - a[i][j + 1] + k) % k][1] = (f[i][j + 1][(h - a[i][j + 1] + k) % k][1] + f[i][j][h][0]) % MOD;
                }
                if (!h)
                {
                    ans = (ans + f[i][j][h][1]) % MOD;
                }
            }
        }
    }

    cout<<ans<<"\n";

    return 0;
}
