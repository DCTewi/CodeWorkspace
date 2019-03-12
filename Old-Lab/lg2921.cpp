#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n;
vector<int> edge[MAXN];
int dfn[MAXN], low[MAXN], ind = 0;
int stk[MAXN], top = 0, vis[MAXN];
int cnt[MAXN], incnt[MAXN], cntn = 0;
int mem[MAXN];

void tarjan(int u)
{
	dfn[u] = low[u] = ++ind;
	stk[++top] = u; vis[u] = 1;

	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i];
		if (!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (vis[v])
		{
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (dfn[u] == low[u])
	{
		int v;
		cntn++;
		do
		{
			v = stk[top--];
			vis[v] = 0;
			incnt[v] = cntn;
			cnt[cntn]++;
		}
		while (u != v);
	}
}

int getAns(int u, int v)
{
	if (incnt[u] == incnt[v]) return 0;
	if (mem[u]) return mem[u];

	int a = cnt[incnt[u]], vv = edge[u][0];
	return mem[u] = a + getAns(vv, u);
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int next_i; scanf("%d", &next_i);
		edge[i].push_back(next_i);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!incnt[i])
		{
			tarjan(i);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", getAns(i, 0));
	}

	return 0;
}