#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e3 + 5;
int a[MAXN], sum[MAXN];

int main()
{
    ios::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        sort(a + 1, a + 1 + n);
        int ans = max(a[n], (int)ceil(sum[n] / k));
        cout << ans << "\n";
    }

    return 0;
}
