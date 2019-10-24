#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll b, p, k;

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

int main(int argc, char const *argv[])
{
	scanf("%lld%lld%lld", &b, &p, &k);

	printf("%lld^%lld mod %lld=%lld\n", b, p, k, qExp(b, p, k));

	return 0;
}