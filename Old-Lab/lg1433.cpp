#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;
int n;
class Cheese
{
public:
	Cheese(){}
	Cheese(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	double x, y;

	double operator<(const Cheese &other) const
	{
		return sqrt((this->x - other.x) * (this->x - other.x) + (this->y - other.y) * (this->y - other.y));
	}
};

Cheese cheese[MAXN];
double len = 0, ans = 0x3ffffff;
int vis[MAXN];
void dfs(Cheese last, int index)
{
	if (len > ans) return ;
	if (index > n) return ;
	if (index == n)
	{
		ans = min(ans, len);
		return ;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			len += last < cheese[i];
			dfs(cheese[i], index + 1);
			len -= last < cheese[i];
			vis[i] = 0;
		}
	}
	return ;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf %lf", &cheese[i].x, &cheese[i].y);
	}

	memset(vis, 0, sizeof(vis));
	cheese[0] = Cheese(0, 0);
	vis[0] = 1;
	dfs(cheese[0], 0);

	printf("%.2f\n", ans);
	return 0;
}