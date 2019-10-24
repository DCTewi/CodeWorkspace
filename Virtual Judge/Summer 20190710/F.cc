// F - Stones in the Bucket 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

ll a[MAXN];

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        ll sum = 0, ans = 0, n;
        scanf("%lld", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
            sum += a[i];
        }
        ll ave = sum / n;
        for (int i = 0; i < n; i++)
        {
            ans += max(0ll, a[i] - ave);
        }
        printf("%lld\n", ans);
    }

    return 0;
}
