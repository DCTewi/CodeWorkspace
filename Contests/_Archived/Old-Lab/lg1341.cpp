#include <bits/stdc++.h>
using namespace std;

const int MAXC = 3e2 + 5;

int n, num = 0;
map<char, vector<char> > edge;
int vis[MAXC];
char path[MAXC]; int top = 0;

int main(int argc, char const *argv[])
{
	cin >>n;

	for (int i = 0; i < n; i++)
	{
		char a, b;cin >>a >>b;

		if (!vis[(int)a])
		{
			vis[(int)a] = 1;
			num++;
		}
		if (!vis[(int)b])
		{
			vis[(int)b] = 1;
			num++;
		}

		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	if (num > n + 1) return 0 * puts("No Solution");

	char root;
	for (auto firs : edge)
	{
		root = firs.first;
		break;
	}

	memset(vis, 0,sizeof(vis));
	queue<char> q;
	q.push(root);
	vis[(int)root] = 1;
	path[top++] = root;

	while (!q.empty())
	{
		char u = q.front(); q.pop();
		for (int i = 0; i < edge[u].size(); i++)
		{
			char v = edge[u][i];

			if (!vis[(int)v])
			{
				path[top++] = v;
				vis[(int)v] = 1;
				q.push(v);

				break;
			}
		}
	}

	if (top != n && top != n + 1)
	{
		puts("No Solution");
	}
	else
	{
		printf("%c", path[0]);
		for (int i = top - 1; i >= (top == n + 1)?1 :0; i--)
		{
			printf("%c", path[i]);
		}
		
	}

	return 0;
}
