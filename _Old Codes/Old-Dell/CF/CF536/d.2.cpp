#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
vector<int> edge[MAXN];
int vis[MAXN];

void dfs(int u)
{
	sort(edge[u].begin(), edge[u].end());
	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i];
		if (vis[v]) continue;
		vis[v] = 1;

		cout<<v<<" ";
		dfs(v);
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n, m; cin>>n>>m;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	vis[1] = 1;
	cout<<"1 ";
	dfs(1);
	cout<<endl;
	return 0;
}