#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e3 + 5;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int t; cin>>t;
	while (t--)
	{
		ll dat[MAXN];
		ll x, n; cin>>x>>n;

		if (n == 1)
		{
			cout<<x<<endl;
		}
		else
		{
			ll loop = x / (2 * n - 2); // loop len
			ll res = x % (2 * n - 2);

			for (int i = 1; i <= n; i++) //loop part
			{
				if (i == 1) 
				{
					dat[i] = loop;
				}
				else if (i == n)
				{
					dat[i] = loop;
				}
				else
				{
					dat[i] = 2 * loop;
				}
			}
			//res part
			if (res <= n)
			{
				for (int i = 1; i <= res; i++)
				{
					dat[i]++;
				}
			}
			else
			{
				for (int i = 1; i <= n; i++)
				{
					dat[i]++;
				}
				for (int i = n - 1, j = n + 1; j <= res; j++, i--)
				{
					dat[i]++;
				}
			}
			//output
			for (int i = 1; i <= n; i++)
			{
				if (i != n) cout<<dat[i]<<" ";
				else cout<<dat[i]<<endl;
			}
		}
	}
	return 0;
}
/*
1 234321 234321
1 2321 2321
1 2321
*/
