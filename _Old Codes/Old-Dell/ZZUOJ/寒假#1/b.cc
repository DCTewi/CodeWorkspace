#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int t; cin>>t;
	while (t--)
	{
		ll x, n; cin>>x>>n;
		ll loop = 2 * n - 2;
		ll num = (x - 1) / loop;
		ll res = (x - 1) % loop;
/*
		cout<<"loop="<<loop<<endl;
		cout<<"res="<<res<<endl;
		cout<<"num="<<num<<endl;
*/
		cout<<(1 + num)<<" ";
		for (ll i = 2; i < n; i++)
		{
			cout<<(num * 2 + ((res >= i - 1)? 1: 0) + (((res != 0) && (loop - res <= i - 1))? 1: 0))<<" ";
		}
		cout<<(num + ((res != 0) && (res >= loop / 2)? 1: 0))<<endl;
	}
	return 0;
}
/*
1 234321 234321
1 2321 2321
1 2321
*/
