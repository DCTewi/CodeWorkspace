#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998254353;
const int MAXN = 1e5 + 5;

ll qpow(ll a, ll k, ll mod)
{
    if (!k) return 1;
    ll ans = 1;
    while (k)
    {
        if (k & 1) ans = ans * a % mod;
        a = a * a % mod;
        k >>= 1;
    }
    return ans;
}

ll inv[MAXN];

struct Node
{
    int l, r;
};

int main()
{
    return 0;
}