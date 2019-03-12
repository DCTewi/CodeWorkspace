#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1000000007;
ll n, m;

ll qExp(ll a, ll b, ll mod)
{
	if (!b) return 0;
	
	ll ans = 1;
	while (b)
	{
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

ll ans = 1;

int main(int argc, char const *argv[])
{
	scanf("%lld%lld", &n, &m);

	if (n == 1)
	{
		printf("%lld\n", m);
	}
	else
	{
		ans = m;
		ans = ans * qExp(m - 1, n - 1, mod) % mod;

		printf("%lld\n", ans);
	}
	
	return 0;
}