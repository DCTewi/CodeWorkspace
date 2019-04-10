#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 998244353;
const int MAXN = 1e5 + 5;
const int MAXQ = 1e4 + 5;
ll c[2000][MAXN];
ll a[MAXN];
int n, q;

void comb(int n)
{
	c[1][0] = c[1][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if(c[i][0] == 1) continue;
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]);
		}
	}
}


int main(int argc, char const *argv[])
{
	memset(c, 0, sizeof(c));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		comb(x);
		ll ans = 0;
		for (int i = 0; i <= x; i++)
		{
			ans += c[x][i] * a[((y + i) >= n)? (y + i) % n + (y + i) / n: y + i] % MOD;
			//printf("%lld %lld %lld %lld\n", c[x][i] * a[(y + i) % n] % MOD, c[x][i], a[(y + i) % n], ans);
		}
		printf("%lld\n", ans);
	}
	return 0;
}