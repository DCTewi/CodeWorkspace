#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 5;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int height[MAXN][MAXN];
int mem[MAXN][MAXN];
int m, n;
int ans = -1;

int read()
{
	int x = 0, w = 0; char ch = getchar();
	while (!isdigit(ch))
	{
		w |= ch == '-';
		ch = getchar();
	}
	while (isdigit(ch))
	{
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return w? -x: x;
}

int mdfs(int x, int y)
{
	if (mem[x][y]) return mem[x][y];

	int tmph = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < m && ny >= 0 && ny < n)
		if (height[nx][ny] > height[x][y])
		{
			tmph = max(tmph, mdfs(nx, ny) + 1);
		}
	}

	return mem[x][y] = tmph;
}

int main()
{
	m = read(), n = read();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			height[i][j] = read();
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ans = max(ans, mdfs(i,j));
		}
	}

	printf("%d\n", ans);

	return 0;
}

