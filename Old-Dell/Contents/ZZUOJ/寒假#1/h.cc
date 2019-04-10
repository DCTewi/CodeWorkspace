#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
int a[MAXN];

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int t; cin>>t;
	while (t--)
	{
		memset(a, 0, sizeof(a));
		int n; cin>>n;
		for (int i = 1; i <= 2 * n; i++)
		{
			cin>>a[i];
		}
		int ans = -1;
		for (int i = 1; i <= n; i++)
		{
			ans = max(ans, a[i] + a[2 * n - i + 1]);
		}
		cout<<ans<<endl;
	}
	return 0;
}