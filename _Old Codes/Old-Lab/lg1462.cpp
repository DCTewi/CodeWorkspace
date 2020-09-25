#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int n, m, b;
int cost[MAXN];
class Edge
{
public:
	Edge(){}
	Edge(int b, int c)
	{
		this->to = b;
		this->damage = c;
 	}

 	int to, damage;
};
vector<Edge> g[MAXN];
int vis[MAXN], cst[MAXN], dmg[MAXN], maxcost = 0x3fffffff;

int read()
{
	int x = 0, f = 0; char ch = getchar();
	while (!isdigit(ch)) 
	{
		f |= ch == '-';
		ch = getchar();
	}
	while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f? -x: x;
}

inline void new_edge(int a, int b, int c)
{
	g[a].push_back(Edge(b, c));
	g[b].push_back(Edge(a, c));
}

void spfa(int start)
{
	memset(cst, 0x3f, sizeof(cst));
	memset(dmg, 0x3f, sizeof(dmg));
	queue<int> q; q.push(start);
	vis[start] = 1; cst[start] = dmg[start] = 0;

	while (!q.empty())
	{
		int u = q.front();
		for (int i = 0; i < g[u].size(); i++)
		{
			int v = g[u][i].to;
			int damage = g[u][i].damage;

			if (dmg[])

		}
		q.pop(); vis[u] = 0;
	}
}

int main(int argc, char const *argv[])
{
	n = read(); m = read(); b = read();
	for (int i = 1; i <= n; i++)
	{
		cost[i] = read();
	}
	for (int i = 1; i <= m; i++)
	{
		int a = read(), b = read(), c = read();
		new_edge(a, b, c);
	}

	spfa(1);

	printf("%d\n", maxcost);

	return 0;
}