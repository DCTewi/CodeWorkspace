//WA
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e3 + 5;
int n, m;
int a[MAXN][MAXN], f[MAXN][MAXN];

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        int ans = 0;
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] && !a[i - 1][j] && !a[i][j - 1])
                {
                    f[i][j] = max(f[i][j], f[i - 1][j - 1]) + 1;
                    ans = max(f[i][j], ans);
                }
            }
        }
        
        printf("%d\n", ans);
    }
    return 0;
}
