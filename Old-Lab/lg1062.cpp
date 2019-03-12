#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll poww(int x, int a)
{
	if (!a) return 1;
	ll ans = 1;
	while (a)
	{
		if (a & 1)
		{
			ans *= x;
		}
		x *= x;
		a >>= 1;
	}
	return ans;
}

int main()
{
	int n, k;
	scanf("%d%d", &k, &n);

	ll ans = 0, idx = 0;
	while (n)
	{
		if (n & 1)
		{
			ans += poww(k, idx);
		}
		idx++;
		n >>= 1;
	}

	printf("%lld\n", ans);

	return 0;
}
