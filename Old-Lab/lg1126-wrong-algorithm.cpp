#include <bits/stdc++.h>
using namespace std;
const int MAXN = 60 + 5;
int n, m;
int x, y, tar_x, tar_y;
int dir;//0, 1, 2, 3  means N E S W;
class Tile
{
public:
	Tile(){}
	Tile(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	int x, y;
};
// N E S W
int directs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int cost[MAXN][MAXN]; //-1 means hav'nt get, -2 means can't get, >=0 means mincost;

queue<Tile> tiles;

int main(int argc, char const *argv[])
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int tmp; scanf("%d", &tmp);
			if (tmp)
			{
				cost[i][j] = cost[i][j + 1] = cost[i + 1][j] = cost[i + 1][j + 1] = -2;
			}
		}
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (cost[i][j] != -2)
			{
				cost[i][j] = -1;
			}
		}
	}
	char tmp; scanf("%d%d%d%d%c", &x, &y, &tar_x, &tar_y, &tmp);
	dir =  (tmp == 'N')? 0: (tmp == 'E')? 1: (tmp == 'S')? 2: (tmp == 'W')? 3: -1;

	tiles.push(Tile(x, y));
	cost[x][y] = 0;

	while(!tiles.empty())
	{
		Tile now = tiles.front();
		tiles.pop();
		for (int i = 3; i > 0; i--)
		{
			int olddir = dir;
			for (int s = 0; s < 4; s++)
			{
				int newx = now.x + directs[s][0], newy = now.y + directs[s][1];
				if (newx >= 0 && newx <= n && newy >= 0 && newy <= m)
				{
					if (cost[newx][newy] == -1)
					{
						tiles.push(Tile(newx, newy));
						cost[newx][newy] = cost[now.x][now.y] + i + abs(dir - s);
						dir = s;
					}
				}
			}
			dir = olddir;
		}
		printf("pop\n");
	}

	if (cost[tar_x][tar_y] == -2 || cost[tar_x][tar_y] == -1)
	{
		printf("-1\n");
	}
	else 
	{
		printf("%d\n", cost[tar_x][tar_y]);
	}

	return 0;
}