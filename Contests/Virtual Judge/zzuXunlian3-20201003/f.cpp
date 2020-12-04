#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n; scanf("%lld", &n);

    if (n <= 4) 
    {
        printf("%lld\n", n * (n - 1LL) / 2LL);
    }
    else
    {
        ll min5 = 5LL, pow10 = 1LL, suf9 = 0LL, len = 0LL;

        while (min5 <= n / 10LL) min5 *= 10LL, len++;
        for (ll i = 0; i <= len; i++)
        {
            suf9 = suf9 * 10LL + 9LL;
            pow10 *= 10LL;
        }

        // cout << min5 << " " << pow10 << " " << suf9 << " " << len << "\n";

        ll ans = 0LL;
        for (ll i = 0LL; i < 9LL; i++)
        {
            ll target = i * pow10 + suf9;

            if (target > n + (n - 1LL)) break;

            if (target <= n)
            {
                ans += target / 2LL;
            }
            else
            {
                ans += ((n - target) + (n - 1)) / 2LL + 1LL;
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}
