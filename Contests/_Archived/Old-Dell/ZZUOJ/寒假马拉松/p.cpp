#include <bits/stdc++.h>
using namespace std;

void calcu(int n,int i,int j)
{
	int ii = i, jj = j;
	for(int k = 1; k <= n; k++)
	{
		printf("(%d,%d)", i, k); 
	}
	printf("\n");
	
	for(int k = 1; k <= n; k++)
	{
		printf("(%d,%d)", k, j); 
	}
	printf("\n");

	if (i > j)
	{
		i -= j - 1; j = 1;
	}
	else
	{
		j -= i - 1; i = 1;
	}
	
	for (; i <= n && j <= n; i++, j++)
	{
		printf("(%d,%d)", i, j);
	}
	printf("\n");

	i = ii;
	j = jj;
	for (; i <= n && j > 0; i++, j--);
	i--;j++;

	for (; i <= n && j <= n && i > 0 && j > 0; i--, j++)
	{
		printf("(%d,%d)",i,j);
	}
}

int main()
{
	int n, i, j;
	scanf("%d%d%d", &n, &i, &j);
	if (i >= 1 && i <= n && j >= 1 && j <= n)
	{
		calcu(n, i, j);
	}
	printf("\n");
	return 0;
}

