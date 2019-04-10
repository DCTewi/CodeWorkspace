#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e5 + 5;
ll a[MAX], tot = 0, ans = 0;
priority_queue<ll> abss;

int main()
{
	ll n, m;cin>>n>>m;
	for (ll i = 0; i < n; i++)
	{
		ll tmp;
		scanf("%I64d%I64d", &a[i], &tmp);
		tot += a[i];
		abss.push(a[i] - tmp);
	}
	if (tot <= m)
	{
		puts("0");
		return 0;
	}
	else while (!abss.empty() && tot > m)
	{
		tot -= abss.top();
		abss.pop();
		ans++;
	}
	if (tot > m)
	{
		puts("-1");
	}
	else
	{
		printf("%I64d\n", ans);
	}

	return 0;
}