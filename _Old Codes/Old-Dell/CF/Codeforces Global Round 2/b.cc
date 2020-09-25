#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
int n, h;
int a[MAXN];
int ans = 0, lef, kon = 0;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n>>h; lef = h;
	for (int i = 2; i <= n + 1; i++)
	{
		cin>>a[i];
	}

	for (int i = 2; i <= n + 1; i++)
	{
		if (lef + kon >= a[i])
		{
			if (!lef)
			{
				ans++;
				break;
			}
			if (lef < a[i])
			{
				kon = min(a[i - 1], a[i - 2]);
				lef = 0;
			}
			else
			{
				kon = abs(a[i] - a[i - 1]);
				lef -= kon;
			}
			ans++;
			cout<<"lef: "<<lef<<" kon: "<<kon<<endl;
		}
		else break;
	}

	cout<<ans<<endl;

	return 0;
}