#include <bits/stdc++.h>
using namespace std;

const int MAXN = 15;
int c[MAXN][MAXN];
int n, sum, a[MAXN];
int found = 0;

void getC(int n)
{
	memset(c, 0, sizeof(c));
	c[0][0] = c[1][0] = c[1][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		c[i][0] = 1;
		for (int j = 0; j <= i; j++)
		{
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
			printf("c[%d][%d] = %d\n", i, j, c[i][j]);
		}
	}
}

void dfs(int nowsum, int index)
{
	if (index > n) return ;
	if (nowsum > sum)
	{
		//found = 1;
		return;
	}
	if (nowsum == sum && index == n)
	{
		found = 1;
		for (int i = 0; i < n; i++)
		{
			printf("%d ", a[i]);
		}
		return ;
	}

	for (int i = 1; i < n && found == 0; i++)
	{
		a[index] = i;
		//printf("a[%d] <= %d, c[%d][%d]=%d\n", index, a[index], n - 1, index, c[n - 1][index]);
		dfs(nowsum + a[index] * c[n - 1][index], index + 1);
		a[index] = 0;
	}

	return ;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &n, &sum);

	getC(n);
	dfs(0, 0);

	return 0;
}