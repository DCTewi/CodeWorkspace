#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1E5 + 5;
int n, d[MAXN];
int ans = 0;

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &d[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		if (d[i] > d[i - 1])
		{
			ans += d[i] - d[i - 1];
		}
	}

	printf("%d\n", ans);
	return 0;
}