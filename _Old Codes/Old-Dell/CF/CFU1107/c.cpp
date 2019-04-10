#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef priority_queue<ll, vector<ll>, less<ll> > pql;

const int MAXN = 2e5 + 5;
ll n, k, ans = 0;
ll dam[MAXN];
string cmd;
pql q;

void clear(pql &q)
{
	pql b;
	swap(q, b);
}

int main()
{
	cin>>n>>k;
	for (ll i = 0; i < n; i++)
	{
		cin>>dam[i];
	}
	cin>>cmd;
	cmd = cmd + " ";

	for (ll i = 0; i < n; i++)
	{
		if (cmd[i] != cmd[i + 1])
		{
			q.push(dam[i]);
		}
		else 
		{
			while (cmd[i] == cmd[i + 1])
			{
				q.push(dam[i++]);
			}
			q.push(dam[i]);
		}

		for (int j = 0; j < k && (!q.empty()); j++)
		{
			ans += q.top();
			q.pop();
		}

		clear(q);
	}

	cout<<ans<<endl;

	return 0;
}
