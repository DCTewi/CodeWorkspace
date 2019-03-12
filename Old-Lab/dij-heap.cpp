#include <cstdio>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

const int MAXN = 1e4 + 5;
const int MAXM = 5e5 + 5;
struct E
{
	int to, cost;
	
	E(int t = 0, int c = 0):to(t), cost(c){}
};
int dis[MAXN], vis[MAXN];
struct P
{
	int n;
	
	bool operator<(const P &oth) const
	{
		return dis[(*this).n] > dis[oth.n];
	}
	
	P(int m):n(m){}
};
priority_queue<P> left;
vector<E> edge[MAXN];
int n, m, s;

void dij(int s);

int main()
{
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 1; i <= m; i++)
	{
		int f, g, w;
		scanf("%d%d%d", &f, &g, &w);
		edge[f].push_back((E){g, w});
	}
	
	dij(s);
	
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", (dis[i] != 0x3f3f3f3f? dis[i]: 0xFFFFffff));
	}
	printf("\n");
	
	return 0;
}

void dij(int s)
{
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	left.push(P(s));
	
	while(!left.empty())
	{
		int u = left.top().n; left.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = 0; i < edge[u].size(); i++)
		{
			int v = edge[u][i].to;
//			if (vis[v]) continue;
			if (dis[v] > dis[u] + edge[u][i].cost)
			{
				dis[v] = dis[u] + edge[u][i].cost;
				left.push(P(v));
			}
		}
	}
	
	return ;
}
 