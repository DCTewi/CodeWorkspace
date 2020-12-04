// B - Digit Product
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
ll jiecheng[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

ll f(ll x)
{
    ll res = 1;
    while (x)
    {
        res = res * (x % 10) % MOD;
        x /= 10;
    }
    return res;
}

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        ll l, r; scanf("%lld%lld", &l, &r);
        if (r - l > 10)
        {
            puts("0");
            continue;
        }

        ll ans = 1;
        for (ll i = l; i <= r; i++)
        {
            ans = ans * f(i) % MOD;
            if (ans == 0) break;
        }

        printf("%lld\n", ans);
    }

    return 0;
}