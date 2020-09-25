#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int n;
map<int, vector<int> > edge;
int dis[MAXN], vis[MAXN];
class Node
{
public:
	Node(){}
	Node(int n)
	{
		this->n = n;
	}
	
	int n;

	bool operator<(const Node &other) const
	{
		return dis[this->n] > dis[other.n];
	}
};
priority_queue<Node> que;
int ans = 0;

void dij(int s)
{
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	que.push(Node(s));

	while (!que.empty())
	{
		int u = que.top().n; que.pop();
		if (vis[u]) continue;
		vis[u] = 1;

		for (int i = 0; i < edge[u].size(); i++)
		{
			int v = edge[u][i];
			if (dis[v] > dis[u] + 1)
			{
				dis[v] = dis[u] + 1;
				que.push(Node(v));
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int f, g;scanf("%d%d", &f, &g);
		edge[f].push_back(g);
		edge[g].push_back(f);
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