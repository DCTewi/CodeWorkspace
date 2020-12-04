#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 3e5 + 50;
ll a[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	int n; cin>>n;

	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}

	sort(a, a + n, [](ll a, ll b)->bool {return a < b;});

	ll ans = 0;

	for (int i = 0; i < n / 2; i++)
	{
		ans += (a[i] + a[n - 1 - i]) * (a[i] + a[n - 1 - i]);
	}

	cout<<ans<<endl;

	return 0;
}