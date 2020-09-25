#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;
int n;
int a[MAXN];
int ans = 0;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}

	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] != a[0])
		{
			ans = i;
			break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] != a[n - 1])
		{
			ans = max(ans, n - i - 1);
			break;
		}
	}

	cout<<ans<<endl;

	return 0;
}