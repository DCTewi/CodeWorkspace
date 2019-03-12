#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e2 + 5;
class Tile
{
public:
	Tile(){}
	Tile(int hi)
	{
		this->height = hi;
	}

	int height, len = 0;
};
class Point
{
public:
	Point(){}
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	int x, y;
};

int directs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
Tile tiles[MAX][MAX];

int r, c;
int maxnow = 0, maxx, maxy = 0;
queue<Point> que;
int maxlen = 0;

int main(int argc, char const *argv[])
{
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			scanf("%d", &tiles[i][j].height);
			if (tiles[i][j].height > maxnow)
			{
				maxnow = tiles[i][j].height;
				maxx = i; maxy = j;
			}
		}
	}

	#ifdef TEWILOCAL
		printf("\n");
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				printf("%d ", tiles[i][j].height);
			}
			printf("\n");
		}
		printf("\n");
	#endif

	que.push(Point(maxx, maxy));
	tiles[maxx][maxy].len = 1;
	//printf("first is %d, %d = %d\n", maxx, maxy, tiles[maxx][maxy].height);
	while (!que.empty())
	{
		Point now = que.front(); que.pop();
		//printf("<<<%d, %d popped\n", now.x, now.y);
		for (int i = 0; i < 4; i++)
		{
			Point newpoint = Point(now.x + directs[i][0], now.y + directs[i][1]);
			if (newpoint.x >= 0 && newpoint.x < r && newpoint.y >= 0 && newpoint.y < c)
			{
				if (tiles[newpoint.x][newpoint.y].height > tiles[now.x][now.y].height)
				{
					continue;
				}
				else if (tiles[newpoint.x][newpoint.y].len < tiles[now.x][now.y].len + 1)
				{
					tiles[newpoint.x][newpoint.y].len = tiles[now.x][now.y].len + 1;
					maxlen = max(tiles[newpoint.x][newpoint.y].len, maxlen);
					que.push(Point(newpoint.x, newpoint.y));
					//printf(">>>%d,%d pushed\n", newpoint.x, newpoint.y);
				}
			}
		}
	}

	printf("%d\n", maxlen);

	return 0;
}