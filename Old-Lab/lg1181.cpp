#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int a[MAX], n, m;
int ans = 1, nowtot = 0;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (nowtot + a[i] > m)
		{
			ans++;
			nowtot = a[i];
		}
		else 
		{
			nowtot += a[i];
		}
	}

	printf("%d\n", ans);

	return 0;
}