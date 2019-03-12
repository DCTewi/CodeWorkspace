#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5, MAXM = 2e6 + 5;
const int MOD = 1e5 + 3;
vector<int> g[MAXN];
int n, m;
int vis[MAXN], dis[MAXN], ans[MAXN];

int readint()
{
	int x = 0, f = 0; char ch = getchar();
	while (!isdigit(ch))
	{
		f |= ch=='-';
		ch = getchar();
	}
	while (isdigit(ch))
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return f? -x: x;
}

inline void new_edge(int x, int y)
{
	g[x].push_back(y);
	g[y].push_back(x);
}

void spfa(int start)
{
	memset(dis, 0x3f, sizeof(dis));

	queue<int> q; q.push(start);
	ans[start] = vis[start] = 1; dis[start] = 0;

	while (!q.empty())
	{
		int u = q.front();
		//printf("for u = %d:\n", u);
		for (int i = 0; i < g[u].size(); i++)
		{
			int v = g[u][i];
			//printf("    %d.v = %d\n", i, v);
			if (dis[v] > dis[u] + 1)
			{
				dis[v] = dis[u] + 1;
				ans[v] = ans[u];
				//printf("      -new-, dis[%d] is now %d & ans[%d] is now %d\n", v, dis[v], v, ans[v]);

				if (!vis[v])
				{
					vis[v] = 1;
					q.push(v);
				}
			}
			else if (dis[v] == dis[u] + 1)
			{
				ans[v] += ans[u];
				ans[v] %= MOD;
				//printf("      ans++, ans[%d] is now %d\n", v, ans[v]);
			}
		}
		q.pop(); vis[u] = 0;
	}
}

int main(int argc, char const *argv[])
{
	n = readint();
	m = readint();
	for (int i = 0; i < m; i++)
	{
		int x = readint(), y = readint();
		new_edge(x, y);
	}

	spfa(1);

	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", ans[i]);
	}

	return 0;
}