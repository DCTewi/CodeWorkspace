#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[])
{
	int t; cin>>t;
	while (t--)
	{
		ll a, ans = 0; scanf("%I64d", &a);

		while (a)
		{
			ans += a & 1;
			a >>= 1;
		}

		printf("%I64d\n", 1ll<<ans);

	}
	return 0;
}