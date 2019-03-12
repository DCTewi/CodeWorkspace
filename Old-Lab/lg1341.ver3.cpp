#include <bits/stdc++.h>
using namespace std;

const int MAXC = 300;

int edge[MAXC][MAXC], vis[MAXC][MAXC], deg[MAXC];
char path[MAXC]; int top = 0;
int n, cnt = 0;
char mchar = 'A' - 1;

void euler(int u)
{
	for (int v = (int)'A'; v <= (int)'z'; v++)
	{
		if (edge[u][v] && !vis[u][v])
		{
			vis[u][v] = vis[v][u] = 1;
			euler(v);

			path[top++] = v;
		}
	}
}

int main(int argc, char const *argv[])
{
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		char a, b; cin >>a >>b;
		edge[(int)a][(int)b] = edge[(int)b][(int)a] = 1;
		deg[(int)a]++;
		deg[(int)b]++;
		mchar = max(mchar, a > b ? a: b);
	}

	for (int i = (int)'A'; i <= (int)'z'; i++)
	{
		if (deg[i] & 1) cnt++;
	}
	if (cnt != 0 && cnt != 2)
	{
		return 0 * puts("No Solution");
	}

	char start;
	if (cnt == 0)//circle
	{
		for (int i = (int)'A'; i <= (int)'z'; i++)
		{
			if (deg[i])
			{
				start = (char)i;
				break;
			}
		}
	}
	else //path
	{
		for (int i = (int)'A'; i <= (int)'z'; i++)
		{
			if (deg[i] && (deg[i] & 1))
			{
				start = (char)i;
				break;
			}
		}
	}

	euler((int)start);

	cout<<start;
	for (int i = top - 1; i >= 0; i--)
	{
		cout<<path[i];
	}


	return 0;
}