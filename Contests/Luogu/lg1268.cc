#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
int n, dis[MAXN][MAXN];

int main()
{
    ios::sync_with_stdio(false);
    
    while (cin >> n, n)
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = 1 + i; j <= n; j++)
            {
                cin >> dis[i][j];
            }
        }

        int ans = dis[1][2];
        for (int i = 3; i <= n; i++)
        {
            int delta = 1 << 30;
            for (int j = 2; j < i; j++)
            {
                delta = min(delta, (dis[1][i] - dis[1][j] + dis[j][i]) / 2);
            }
            ans += delta;
        }

        cout << ans << "\n";
    }

    return 0;
}

// dis(1, 2) + Sigma_3^n min_2^(i-1) {dis(1, i) + dis(i, j) - dis(1, j)}/2