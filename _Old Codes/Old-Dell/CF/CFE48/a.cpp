#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 5;
int n, m;
int a[MAX];

int32_t main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int left = m;
	for (int i = 0; i < n; i++)
	{
		int t = 0;

		if (a[i] >= left)
		{
			a[i] -= left; t++;
			t += a[i] / m;
			a[i] %= m;
			left = m - a[i];
		}
		else left -= a[i];

		printf("%d ", t);
	}
	printf("\n");

	return 0;
}