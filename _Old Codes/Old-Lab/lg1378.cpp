#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10;
const double pi = 3.14159;

struct Node
{
	Node(){}
	Node(double x, double y)
	{
		this->x = x;
		this->y = y;
	}

	double x, y, r = 0;

}node[MAXN];
double dis[MAXN][MAXN];
bool vis[MAXN];
double size, ans;

double x1, y_1, x2, y2;
int n;

inline double getD(int a, int b)
{
	if (dis[a][b]) return dis[a][b] < node[a].r? 0: dis[a][b] - node[a].r;
	if (dis[b][a])
	{
		dis[a][b] = dis[b][a];
		return dis[a][b] < node[a].r? 0: dis[a][b] - node[a].r;
	}   

	double ans = (node[a].x - node[b].x) * (node[a].x - node[b].x) 
					+ (node[a].y - node[b].y) * (node[a].y - node[b].y);
	dis[a][b] = sqrt(ans);

	return dis[a][b] < node[a].r? 0: dis[a][b] - node[a].r;
}

void getR(int p)
{
	double x = node[p].x, y = node[p].y;
	if (x <= x1 && x <= x2 || x >= x1 && x >= x2 || y <= y_1 && y <= y2 || y >= y_1 && y >= y2)
	{
		return;
	}
	double maxr = min(abs(x - x1), abs(x - x2));
	maxr = min(abs(y - y_1), maxr);
	maxr = min(abs(y - y2), maxr);

	for (int i = 0; i < n; i++)
	{
		if (vis[i] && i != p)
		{
			maxr = min(getD(i, p), maxr);
		}
	}

	node[p].r = maxr;
}

void dfs(int p)
{
	if (p > n)
	{
		double s = 0.0;
		for (int i = 0; i < n; i++)
		{
			s += pi * node[i].r * node[i].r;
		}
		ans = min(size - s, ans);
		return ;
	}

	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			vis[i] = true;
			getR(i);
			dfs(p + 1);
			vis[i] = false;
		}
	}
}

int main()
{
	scanf("%d%lf%lf%lf%lf", &n, &x1, &y_1, &x2, &y2);
	for (int i = 0; i < n; i++)
	{
		double tx, ty; scanf("%lf%lf", &tx, &ty);
		node[i] = Node(tx, ty);
	}

	size = ans = abs(x1 - x2) * abs(y_1 - y2);

	dfs(1);
	
	printf("%.0lf\n", ans - 0.5);

	return 0;
}
