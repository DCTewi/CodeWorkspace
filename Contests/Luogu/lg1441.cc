#include <bits/stdc++.h>
using namespace std;

const int MAXS = 2e4 + 5;
const int MAXN = 2e1 + 5;
int n, m;
int a[MAXN], f[MAXS], out[MAXN];

int ret = 0;

void dp()
{
	memset(f, 0, sizeof(f)); f[0] = 1;
	int ans = 0, tot = 0;

	for (int i = 0; i < n; i++)
	{
		if (out[i]) continue;
		for (int j = tot; j >= 0; j--)
		{
			if (f[j] && !f[j + a[i]])
			{
				f[j + a[i]] = 1;
				ans++;
			}
		}
		tot += a[i];
	}
	ret = max(ret, ans);	
}

void dfs(int cur, int now)
{
	if (now > m) return;
	if (cur == n)
	{
		if (now == m) dp();
		return;
	}

	dfs(cur + 1, now);
	out[cur] = 1;
	dfs(cur + 1, now + 1);
	out[cur] = 0;
}


int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}

	dfs(0, 0);

	cout<<ret<<endl;

	return 0;
}
