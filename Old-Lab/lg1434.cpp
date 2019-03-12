#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 5;
int height[MAXN][MAXN], len[MAXN][MAXN];
int r, c;
int ans = 0;

int directs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int dfs(int x, int y)
{
	if (len[x][y]) return len[x][y];
	int maxl = 1;
	for (int i = 0; i < 4; i++)
	{
		int newx = x + directs[i][0], newy = y + directs[i][1];
		if (newx > 0 && newx <= r && newy > 0 && newy <= c && height[x][y] < height[newx][newy])
		{
			maxl = max(dfs(newx, newy) + 1, maxl);
		}
	}
	len[x][y] = maxl;
	return maxl;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &r, &c);
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			scanf("%d", &height[i][j]);
		}
	}
	memset(len, 0, sizeof(len));
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			ans = max(dfs(i, j), ans);
			//printf("%d ", dfs(i,j));
		}
		//printf("\n");
	}

	printf("%d\n", ans);
	return 0;
}
