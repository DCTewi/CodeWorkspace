#include <bits/stdc++.h>
using namespace std;

const int MAXC = 300;

int edge[MAXC][MAXC], vis[MAXC][MAXC], used[MAXC];
char path[MAXC]; int top = 0;
int n, usen = 0;

void euler(int u)
{
	for (int v = 'A'; v <= 'z'; v++)
	{
		if (edge[u][v] && !vis[u][v])
		{
			vis[u][v] = vis[v][u] = 1;
			euler(v);

			path[top++] = u;
		}
	}
}

int main(int argc, char const *argv[])
{
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		char a, b; cin>>a>>b;
		edge[(int)b][(int)a] = edge[(int)a][(int)b] = 1;

		if (!used[(int)a])
		{
			used[(int)a] = 1;
			usen++;
		}
		if (!used[(int)b])
		{
			used[(int)b] = 1;
			usen++;
		}
	}
	if (usen > n + 1) return 0 * puts("No Solution");



	return 0;
}