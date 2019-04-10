#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
struct Edge
{
	int to;
	ll cost;

	Edge(int t = 0, ll c = 0)
	{
		this->to = t;
		this->cost = c;
	}
};

vector<Edge> edge[MAXN];
int n;
ll dis[MAXN];
int vis[MAXN];
map<int, int> used[MAXN];

void spfa(int s)
{
	queue<int> q;
	memset(dis, 0x3f, sizeof(dis));
	vis[s] = 1; dis[s] = 0;
	q.push(s);

	while (q.size())
	{
		int u = q.front();
		for (int i = 0; i < edge[u].size(); i++)
		{
			int v = edge[u][i].to;
			ll cost = edge[u][i].cost;
			if (dis[v] > dis[u] + cost)
			{
				dis[v] = dis[u] + cost;

				if (!vis[v])
				{
					vis[v] = 1;
					q.push(v);
				}
			}
		}
		q.pop();
		vis[u] = 0;
	}
}

inline void addEdge(int u, int v, ll cost)
{
	edge[u].push_back(Edge(v, cost));
	edge[v].push_back(Edge(u, cost));
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v; ll c;
		cin>>u>>v>>c;
		addEdge(u, v, c);
	}

	
	
	
	
	return 0;
}
