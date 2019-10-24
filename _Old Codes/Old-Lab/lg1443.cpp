#include <bits/stdc++.h>
using namespace std;

const int MAX = 5e2 + 5;
const int direct[8][2] = {{1, 2}, {2, 1}, {-1, -2}, {-2, -1}, {1, -2}, {-1, 2}, {-2, 1}, {2, -1}};
int n, m;

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
queue<Tile> tiles;
int vis[MAX][MAX];



int main(int argc, char const *argv[])
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			vis[i][j] = -1;
		}
	}

	int x, y; scanf("%d%d", &x, &y);
	tiles.push(Tile(x, y));
	vis[x][y] = 0;

	while (!tiles.empty())
	{
		Tile now = tiles.front();
		for (int i = 0; i < 8; i++)
		{
			int newx = now.x + direct[i][0], newy = now.y + direct[i][1];
			if (newx > 0 && newx <= n)
			{
				if (newy > 0 && newy <= m)
				{
					if (vis[newx][newy] == -1)
					{
						tiles.push(Tile(newx, newy));
						vis[newx][newy] = vis[now.x][now.y] + 1;
					}
				}
			}
		}
		tiles.pop();
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			printf("%-5d", vis[i][j]);
		}
		printf("\n");
	}

	return 0;
}