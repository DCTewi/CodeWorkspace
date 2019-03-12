#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll gcd(ll a, ll b)
{
	return (b == 0)? a: gcd(b, a % b);
}

int main(int argc, char const *argv[])
{
	ll x, y; scanf("%lld%lld", &x, &y);
	ll tot = x * y;

	ll ans = 0;
	for (ll i = x; i <= y; i++)
	{
		if (tot / i * i == tot)
		{
			if (gcd(tot / i, i) == x)
			{
				ans++;
			}
		}
	}

	printf("%lld\n", ans);

	return 0;
}