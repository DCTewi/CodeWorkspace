#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

ll q_pow(ll a, ll k, ll mod)
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

int main()
{
    ios::sync_with_stdio(false);

    ll n; cin>>n;
    if (n == 1) return 0 * puts("1");

    n -= 2;
    
    cout<< 4LL * q_pow(3LL, n, MOD) % MOD<<"\n";

    return 0;
}