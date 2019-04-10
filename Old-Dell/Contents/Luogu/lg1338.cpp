#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 5e4 + 5;
int n, m, a[MAXN];

signed main(signed argc, char const *argv[])
{
	scanf("%lld%lld", &n, &m);
	
	int l = n, r= 1;

	for (int i = 1; i <= n; i++)
	{
		int t = (int)(n - i) * (n - i - 1) / 2;
		if (t >= m)
		{
			a[r++] = i;
		}
		else a[l--] = i, m -= (l - r + 1);
	}

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}

	return 0;
}