#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
int n, m;
int tile[MAXN][MAXN];
int maxS = 0, ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string tmp; cin >> tmp;
        for (int j = 1; j <= m; j++)
        {
            tile[i][j] = tmp[j - 1] - '0';
            tile[i][j] += tile[i - 1][j] * tile[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int len = tile[i][j], wid = 1;
            while (len)
            {
                int now = len * wid;
                if (now > maxS)
                {
                    ans = maxS; maxS = now;
                }
                else if (now > ans) ans = now;

                len = min(len, tile[i][j - wid]);
                wid++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
