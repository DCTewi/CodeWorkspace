#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAX = 1e6 + 5;
const int MAXQ = 1e4 + 5;
int n, q;
int que[MAX][MAXQ];

void doo(int x)
{
	if (timenow == x) return;
	if (timenow < x)
	for (int i = 1; i <= x - timenow; i++)
	{
		que[i][timenow] = que[i % n + 1][timenow - 1] + que[i][timenow - 1];
	}
	return ;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &que[i]);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		for (int j = 0; j < x; j++)
		{
			doo(x);
		}
		printf("%d\n", que[y]);
	}
	return 0;
}