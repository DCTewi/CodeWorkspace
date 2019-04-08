#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e2 + 5;
int n, M, T;
int m[MAXN], t[MAXN];
int ans = 0;
int f[MAXN][MAXN];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>M>>T;
    for (int i = 1; i <= n; i++)
    {
        cin>>m[i]>>t[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = M; j >= 0; j--)
        {
            if (j >= m[i])
            for (int k = T; k >= 0; k--)
            {
                if (k >= t[i])
                {
                    f[j][k] = max(f[j][k], f[j - m[i]][k - t[i]] + 1);
                    ans = max(ans, f[j][k]);
                }
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}
