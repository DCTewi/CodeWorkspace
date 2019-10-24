#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
const int MAXM = 1e5 + 5;

int n, m, tot = 0;
int vis[MAXN], color[MAXN], ans[2] = {0, 0};
vector<int> edge[MAXN];
queue<int> q;

void bfs(int fromp)
{
	while (!q.empty())
	{
		int u = q.front();
		vis[u] = 1;
		q.pop();

		int size = edge[u].size();
		for (int i = 0; i < size; i++)
		{
			int v = edge[u][i];
			if (color[u] == color[v])
			{
				ans[0] = ans[1] = -1;
				return ;
			}

			if (!vis[v])
			{
				//printf("%d- %d\n", u, v);
				q.push(v);
				color[v] = (color[u] + 1) % 2;
				ans[color[v]]++;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	memset(color, 0x3f, sizeof(color));
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
			ans[0] = 1;
			ans[1] = 0;
			color[i] = 0;
			q.push(i);

			bfs(i);
			if (ans[0] == -1)
			{
				return 0 * puts("Impossible");
			}
			else
			{
				tot += min(ans[0], ans[1]);
			}
		}
	}

	return 0 * printf("%d\n", tot);;
}