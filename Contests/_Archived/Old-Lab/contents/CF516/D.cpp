#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3 + 5;
const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int tile[MAXN][MAXN];
int vis[MAXN][MAXN];
int m, n;
int sx, sy;
int l, r;
int ans = 0;

void gogogo(int x, int y)
{
	if (x <= 0 || x > m || y <= 0 || y > n) return ;
	if (tile[x][y] == 1) ans++;
	tile[x][y]++;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dir[i][0], ny = y + dir[i][1];
		if (!vis[nx][ny] && tile[nx][ny] != 0)
		{
			if (i == 0 && r <= 0) continue;
			if (i == 1 && l <= 0) continue;

			vis[nx][ny] = 1;
			if (i == 0) l--;
			if (i == 1) r--;

			gogogo(nx, ny);

			vis[nx][ny] = 0;
			if (i == 0) l++;
			if (i == 1) r++;
		}
	}
}

int main(int argc, char const *argv[])
{
	cin>>m>>n>>sx>>sy>>l>>r;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			char ch; cin>>ch;
			tile[i][j] = (ch == '*'? 0: 1);
		}
	}

	vis[sx][sy] = 1;
	gogogo(sx, sy);

	printf("%d\n", ans - 3);
	return 0;
}