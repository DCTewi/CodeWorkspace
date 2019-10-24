#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int dis[MAXN], vis[MAXN];
int n;
int ans = 0;

class Edge
{
public:
	Edge(){}
	Edge(int t, int c)
	{
		this->to = t;
		this->cost = c;
	}

	int to, cost;
};
class Point
{
public:
	Point(){}
	Point(int n)
	{
		this->n = n;
	}
	int n;

	bool operator<(const Point &other)const
	{
		return dis[this->n] > dis[other.n];
	}
};

priority_queue<Point> que;
vector<Edge> edge[MAXN];

void dij(int s)
{
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	que.push(Point(s));

	while(!que.empty())
	{
		int u = que.top().n; que.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = 0; i < edge[u].size(); i++)
		{
			int v = edge[u][i].to;
			if (dis[v] > dis[u] + edge[u][i].cost)
			{
				dis[v] = dis[u] + edge[u][i].cost;
				que.push(Point(v));
			}
		}
	}
	return;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int f, g, w; scanf("%d%d%d", &f, &g);
		edge[f].push_back(Edge(g, 1));
		edge[g].push_back(Edge(f, 1));
	}

	dij(1);

	for (int i = 2; i <= n; i++)
	{
		ans += dis[i];
	}

	for (int i = 1; i <= n; i++)
	{
		if (edge[i].size() > 1)
		{
			ans -= edge[i].size() - 1;
		}
	}

	printf("%d\n", ans);

	return 0;
}