#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
const int MAXM = 1e5 + 5;

int n, m, ans = -1;
vector<int> edge[MAXN];
queue<int> q;
int vis[MAXN], color[MAXN];

void bfs(int fir)
{
	int nowcolor = 1, thisans = 1;

	q.push(fir);
	color[fir] = nowcolor;
	while (!q.empty())
	{
		int u = q.front(), size = edge[u].size();
		q.pop();
		vis[u] = 1;

		for (int i = 0; i < size; i++)
		{
			int v = edge[u][i];

			if (vis[v] && color[v] == nowcolor)
			{
				return ;
			}

			if (!vis[v])
			{
				color[v] = -1 * nowcolor;
				if (color[v] == 1) thisans++;
				q.push(v);
			}
		}

		nowcolor *= -1;
	}

	if (ans == -1)
	{
		ans = min(thisans, n - thisans) + 1;
	}
	else
	{
		thisans = min(n - thisans, thisans);
		ans += min(thisans, ans);
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b; scanf("%d%d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			bfs(i);
		}
	}

	ans == -1? puts("Impossible"): printf("%d\n", ans);

	return 0;
}