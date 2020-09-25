#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 3e2 + 5;
int n;
ll ans = 0;
ll a[MAXN], f[MAXN][MAXN];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        a[i + n] = a[i];
    }
    
    for (int len = 3; len <= n + 1; len++)
    {
        for (int l = 0; l + len - 1 < 2 * n; l++)
        {
            int r = l + len - 1;
            for (int k = l + 1; k < r; k++)
            {
                f[l][r] = max(f[l][r], f[l][k] + f[k][r] + a[l] * a[k] * a[r]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, f[i][i + n]);
    }
    cout<<ans<<"\n";

    return 0;
}