#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 998244353;
typedef long long ll;
ll qmi(ll a, ll b)
{
    ll res = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1)
            res = res * a % mod;
    return res;
}
ll ans[maxn];
void init()
{
    ans[0] = 1;
    for (int i = 1; i < maxn; ++i)
    {
        ans[i] = ans[i - 1] * i % mod * qmi(4 * i + 2, mod - 2) % mod;
    }
}
int main()
{
    init();
    int n;
    while (~scanf("%d", &n))
        printf("%lld\n", ans[n]);
    return 0;
}