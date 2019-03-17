#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
int n;
ll cost[MAXN], val[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		ll u, v, c; cin>>u>>v>>c;
		val[v] = c;
		if (c > 0 && val[u] < 0)
		{
			cost[v] = c;
		}
		else
		{
			cost[v] = cost[u] + val[v];
		}
	}

	return 0;
}

//nooooooo  it dont right
