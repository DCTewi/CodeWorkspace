#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1E5 + 5;
vector<int> g[MAXN];
int n, m, vis[MAXN];
queue<int> ans;

void bfs(int s)
{
	priority_queue<int, vector<int>, greater<int> > q;
	q.push(s);
	vis[1] = 1;
	while (!q.empty())
	{
		int v = q.top();
		q.pop();
		ans.push(v);

		for (int i = 0; i < g[v].size(); i++)
		{
			if (!vis[g[v][i]])
			{
				q.push(g[v][i]);
				vis[g[v][i]] = 1;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	cin>>n>>m;
	for (int i = 0; i < m; i++)
	{
		int u, v; cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	bfs(1);

	while (!ans.empty())
	{
		cout<<ans.front()<<" ";
		ans.pop();
	}
	cout<<endl;
	return 0;
}