#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
const int INF = 1 << 30;
struct Edge
{
	int v, next;
   	ll w;
}edge[MAXN];
int head[MAXN], e, q[MAXN], vis[MAXN], d[MAXN];

int n;

void init()
{
	e = 0;
	memset(head, -1, sizeof(head));
}

void add(int u, int v, int w)
{
	edge[e].v = v;
	edge[e].w = w;
	edge[e].next = head[u];
	head[u] = e++;
}

void bfs(int src)
{
	for (int i = 1; i <= n; i++)
	{
		vis[i] = 0;
		d[i] = INF;
	}
	int h = 0, t = 0;
	q[t++] = src;
	vis[src] = 1;
	d[src] = 0;

	while (h < t)
	{
		int u = q[h++];
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].v;
			int w = edge[i].w;
			if (d[u] + w < d[v])
			{
				d[v] = d[u] + w;
				if (!vis[v])
				{
					q[t++] = v;
					vis[v] = 1;
				}
			}
		}
	}
}

int pos1, pos2;
map<int, int> path;

bool dfs(int p)
{
cout<<"now is "<<p<<" and: ";
	if (p == pos2)
	{
		return true;
	}

	for (int i = head[p]; i != -1; i = edge[i].next)
	{
		int v = edge[p].v;
		if (!vis[v])
		{
			cout<<v<<" ";
			vis[v] = 1;
			path[v] = 1;
			if (!dfs(v)) path.erase(v);
			vis[v] = 0;
		}
	}
	cout<<endl;
	return false;
}

int main() 
{ 
	ios::sync_with_stdio(false);
	cin>>n;

	init();
	int u, v, w;
	for (int i = 1; i < n; i++)
	{
		cin>>u>>v>>w;
		add(u, v, w);
		add(v, u, w);
	}
	bfs(1);
//	int pos1 = -1, pos2 = -1;
	int	mx = -1;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] > mx)
		{
			mx = d[i];
			pos1 = i;
		}
	}

	bfs(pos1);

	mx = -1;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] > mx) mx = d[i], pos2 = i;
	}
	cout<<mx<<endl;
/*
	memset(vis, 0, sizeof(vis));
	path[pos1] = vis[pos1] = 1;
	dfs(pos1);

	cout<<pos1<<" -- "<<pos2<<endl<<"max = "<<mx<<endl;
	for (auto it : path)
	{
		cout<<it.second<<" ";
	}
	cout<<endl;
*/
	return 0;
}
