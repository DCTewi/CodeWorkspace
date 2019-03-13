#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e2 + 5;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int n, m, cnt;
int dp[MAXN][MAXN], height[MAXN][MAXN];

inline bool search(int x, int y)
{
	if (dp[x][y]) return true;
	if (x == 1)
	{
		dp[x][y] = 1;
		return true;
	}

	for (int i = 1; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 1 || nx > n || ny < 1 || ny > m) continue;


	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin>>n>>m; cnt = n * m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin>>height[i][j];
		}
	}

	for (int i = 1; i <= m; i++)
	{
		search(n, i);
		
	}

	return 0;
}