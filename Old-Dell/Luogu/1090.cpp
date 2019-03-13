#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

priority_queue<ll, vector<ll>, greater<ll> > q;
ll ans = 0;

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		ll tmp;
		scanf("%lld", &tmp);
		q.push(tmp);
	}

	while(q.size() > 1)
	{
		ll top = q.top(); q.pop();
		top += q.top(); q.pop();

		q.push(top);
		ans += top;
	}

	printf("%lld\n", ans);
	return 0;
}