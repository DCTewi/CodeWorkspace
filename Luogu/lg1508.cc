#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e2 + 5;

int a[MAXN][MAXN], f[MAXN][MAXN];
int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin>>m>>n;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin>>a[i][j];
		}
	}

	for (int i = 1; i <= m + 1; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			f[i][j] = max(f[i - 1][j - 1],
					max(f[i - 1][j], f[i - 1][j + 1])) + a[i][j];
		}
	}

	cout<<f[m + 1][n / 2 + 1]<<endl;

	return 0;
}
