#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, m, s = 0;
	int kick[105];
	scanf("%d%d", &n, &m);
	memset(kick, 0, sizeof(kick));
	for (int k = 0; k < n; k++)
	{
		for (int i = 1; i <= m; i++)
		{
			if (++s > n) s = 1;
			if (kick[s]) i--;
		}
		printf("%d ", s); kick[s] = 1;
	}
	printf("\n");
	return 0;
}