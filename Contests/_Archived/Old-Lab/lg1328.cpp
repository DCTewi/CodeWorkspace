#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e2 + 5;
const int awin[5][5] = 
{
	0, 0, 1, 1, 0,
	1, 0 ,0, 1, 0, 
	0, 1, 0, 0, 1,
	0, 0, 1, 0, 1,
	1, 1, 0, 0, 0
};
int n, na, nb;
int a[MAXN], b[MAXN];
int ansa = 0, ansb = 0;

int main()
{
	scanf("%d%d%d", &n, &na, &nb);
	for (int i = 0; i < na; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < nb; i++)
	{
		scanf("%d", &b[i]);
	}

	for (int i = na; i < n; i++)
	{
		a[i] = a[i % na];
	}
	for (int i = nb; i < n; i++)
	{
		b[i] = b[i % nb];
	}

	for (int i = 0; i < n; i++)
	{
		ansa += awin[a[i]][b[i]];
		ansb += awin[b[i]][a[i]];
	}

	printf("%d %d\n", ansa, ansb);
	return 0;
}
