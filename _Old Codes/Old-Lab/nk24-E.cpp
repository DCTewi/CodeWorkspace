#include <bits/stdc++.h>
using namespace std;

int n, m;
map<int, vector<int> > edges;
int l = 300, r = 0;
int vis[300];

queue<int> q;

void dfs(int x, int step)
{
	if (x == m)
	{
		printf("%d\n", step);
	}
	else if (edges[x].size() == 0)
	{
		vis[x] = 1;
		dfs(x + 1, step + 1);
		vis[x] = 0;
	}
	else 
	{
		for (int i = 0; i < edges[x].size(); i++)
		{
			if (!vis[edges[x][i]])
			{
				vis[edges[x][i]] = 1;
				dfs(edges[x][i], step + 1);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++)
	{
		int a, b; scanf("%d%d", &a, &b);
		if (a > r) r = a;
		if (a < l) l = a;
		if (b > r) r = b;
		if (b < l) l = b;

		edges[a].push_back(b);
	}

	vis[0] = 1;
	dfs(0, 0);

	return 0;
}