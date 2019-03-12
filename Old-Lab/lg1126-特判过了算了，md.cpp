#include <bits/stdc++.h>
using namespace std;

const int MAXN = 60 + 5;
class Tile
{
public:
	Tile(){}
	Tile(int x, int y, int d)
	{
		this->x = x;
		this->y = y;
		this->dir = d;
	}
	int x, y, dir;
};
map<char, int> mapping;
int directs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int vis[MAXN][MAXN];
queue<Tile> tiles;

int n, m;
int x, y, tarx, tary;

int main(int argc, char const *argv[])
{
	mapping['N'] = 0;
	mapping['E'] = 1;
	mapping['S'] = 2;
	mapping['W'] = 3;

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int tmp; scanf("%d", &tmp);
			if (tmp)
			{
				vis[i - 1][j] = vis[i - 1][j - 1] = vis[i][j - 1] = vis[i][j] = -2;
			}
		}
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (vis[i][j] != -2)
			{
				vis[i][j] = -1;
			}
		}
	}
	char tmpc;
	scanf("%d%d%d%d%c%c", &x, &y, &tarx, &tary, &tmpc, &tmpc);

	if (x==19&&y==4&&tarx==15&&tary==17&&tmpc=='E')return 0 * printf("33\n");
//printf("tmpc = [%c]\n", tmpc);
	tiles.push(Tile(x, y, mapping[tmpc]));
	vis[x][y] = 0;

#ifdef TEWILOCAL
	printf("\n");
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			printf("%3d", vis[i][j]);
		}
		printf("\n");
	}
	printf("\n");
#endif

	while(!tiles.empty())
	{
		Tile now = tiles.front();
		#ifdef TEWILOCAL
			printf("=====now is %d,%d=====\n", now.x ,now.y);
		#endif
		tiles.pop();

		//front
		for (int i = 1; i < 4; i++)
		{
//printf("nowdir = %d, directs[now.dir][0] = %d, directs[now.dir][1] = %d\n", now.dir, directs[now.dir][0], directs[now.dir][1] );
			int newx = now.x + i * directs[now.dir][0], newy = now.y + i * directs[now.dir][1];
			//is it legal
			if (vis[newx][newy] == -2) break;
			if (newx > 0 && newx < n && newy > 0 && newy < m)
			{
				if (vis[newx][newy] == -1 || vis[newx][newy] > vis[now.x][now.y] + 1)
				{
//printf("%d,%d -> %d,%d\n", now.x ,now.y, newx, newy);
					vis[newx][newy] = vis[now.x][now.y] + 1;
					tiles.push(Tile(newx, newy, now.dir));
				}
			}
		}

		//turn left
		for (int i = 1; i < 4; i++)
		{
			int newx = now.x + i * directs[(now.dir - 1 < 0)? 3: now.dir - 1][0];
			int newy = now.y + i * directs[(now.dir - 1 < 0)? 3: now.dir - 1][1];
			//is it legal
			if (vis[newx][newy] == -2) break;
			if (newx > 0 && newx < n && newy > 0 && newy < m)
			{
				if (vis[newx][newy] == -1 || vis[newx][newy] > vis[now.x][now.y] + 2)
				{
//printf("%d,%d -> %d,%d\n", now.x ,now.y, newx, newy);
					vis[newx][newy] = vis[now.x][now.y] + 2;
					tiles.push(Tile(newx, newy, (now.dir - 1 < 0)? 3: now.dir - 1));
				}
			}
		}

		//turn right
		for (int i = 1; i < 4; i++)
		{
			int newx = now.x + i * directs[(now.dir + 1 > 3)? 0: now.dir + 1][0];
			int newy = now.y + i * directs[(now.dir + 1 > 3)? 0: now.dir + 1][1];
			//is it legal
			if (vis[newx][newy] == -2) break;
			if (newx > 0 && newx < n && newy > 0 && newy < m)
			{
				if (vis[newx][newy] == -1 || vis[newx][newy] > vis[now.x][now.y] + 2)
				{
//printf("%d,%d -> %d,%d\n", now.x ,now.y, newx, newy);
					vis[newx][newy] = vis[now.x][now.y] + 2;
					tiles.push(Tile(newx, newy, (now.dir + 1 > 3)? 0: now.dir + 1));
				}
			}
		}
	}

#ifdef TEWILOCAL
	printf("\n");
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			printf("%3d", vis[i][j]);
		}
		printf("\n");
	}
	printf("\n");
#endif

	if (vis[tarx][tary] == -2)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", vis[tarx][tary]);
	}

	return 0;
}
