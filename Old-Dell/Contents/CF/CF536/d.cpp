#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> edge[MAXN], ans;
int n, m, flag = 0;
int vis[MAXN], inans[MAXN];

void bfs(int u)
{
	if (!edge[u].size()) return;

	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i];
		if (!inans[u])
		{
			ans.push_back(u);
			inans[u] = 1;
		}
		if (!vis[v])
		{
			vis[v] = 1;
			bfs(v);
			vis[v] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;

	for (int i = 0; i < m; i++)
	{
		int p1, p2; cin>>p1>>p2;
		edge[p1].push_back(p2);
		edge[p2].push_back(p1);
	}

	for (int i = 0; i < n; i++)
	{
		sort(edge[i].begin(), edge[i].end(), [](int a, int b)->bool{return a < b;});
	}

	bfs(1);

	for (int it : ans)
	{
		cout<<it<<" ";
	}
	cout<<endl;

	return 0;
}