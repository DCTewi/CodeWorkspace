#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int MAXN = 1e4 + 5;
const int INF = 0x3f3f3f3f;

vector<P> edge[MAXN];
int dis1[MAXN], dis2[MAXN], vis[MAXN];
int n, m;

void spfa(int s, int dis[])
{
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(int) * n);

	queue<int> q;
	q.push(s); vis[s] = 1; dis[s] = 0;
	while (q.size())
	{
		int u = q.front(); q.pop(); vis[u] = 0;
		for (auto &now : edge[u])
		{
			int v = now.first, w = now.second;
			if (dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				if (!vis[v])
				{
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n>>m;
	for (int i = 0; i < m; i++)
	{
		int u, v, w; cin>>u>>v>>w;
		edge[u].push_back(P(v, w));
		edge[v].push_back(P(u, w));
	}

	spfa(0, dis1);
	spfa(n - 1, dis2);

	int ans = 0;
	for (int u = 0; u < n; u++)
	{
		for (auto &now : edge[u])
		{
			if (dis1[u] + dis2[now.first] + now.second == dis2[0])
			{
				ans += now.second;
			}
		}
	}

	cout<<ans * 2<<endl;

	return 0;
}