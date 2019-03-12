#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 5;
int height[MAXN][MAXN], len[MAXN][MAXN];
int directs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int r, c;
int ans = 0;

void dfs(int x, int y)
{

	if (x < 0 || x >= r || y < 0 || y >= c) return;

	for (int i = 0; i < 4; i++)
	{
		int newx = x + directs[i][0], newy = y + directs[i][1];
		if (len[newx][newy] == 0 || height[newx][newy] < height[x][y] + 1)
		{
			len[newx][newy] = height[x][y] + 1;
			ans = max(ans, len[newx][newy]);
			dfs(newx, newy);
		}
	}
}

int main(int argc, char const *argv[])
{
	int maxh = 0, maxx = 0, maxy = 0;
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			scanf("%d", &height[i][j]);
			if (height[i][j] > maxh)
			{
				maxh = height[i][j];
				maxx = i;
				maxy = j;
			}
		}
	}
	memset(len, 0, sizeof(len));
	len[maxx][maxy] = 1;
	dfs(maxx, maxy);

	printf("%d\n", ans - 1);

	return 0;
}