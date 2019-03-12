#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30 + 5;
const int direct[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int sqr[MAXN][MAXN], vis[MAXN][MAXN];
int n;

void bfs(int x, int y)
{
	//printf("(%d, %d)now\n", x, y);
	if (sqr[x][y])
	{
		//printf("(%d, %d) is %d, so back\n", x, y, sqr[x][y]);
		return;
	}
	else 
	{
		vis[x][y] = 1;
		sqr[x][y] = 2;
		for (int i = 0; i < 4; i++)
		{
			if (x + direct[i][0] >= 0 && y + direct[i][1] >= 0)
			{
				if (x + direct[i][0] < n && y + direct[i][1] <n)
				{
					//printf("try (%d, %d)\n", x + direct[i][0], y + direct[i][1]);
					if (!vis[x + direct[i][0]][y + direct[i][1]]) bfs(x + direct[i][0], y + direct[i][1]);
				}
			}
		}
		vis[x][y] = 0;
	}
}

int main(int argc, char const *argv[])
{
	memset(vis, 0, sizeof(vis));
	scanf("%d", &n);
	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &sqr[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		bfs(i, 0);
		bfs(i, n - 1);
		bfs(0, i);
		bfs(n - 1, i);
	}

	#ifdef TEWILOCAL
		cout<<endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout<<sqr[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	#endif

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!sqr[i][j]) printf("2 ");
			else if (sqr[i][j] == 1) printf("1 ");
			else printf("0 ");
		}
		printf("\n");
	}

	return 0;
}
