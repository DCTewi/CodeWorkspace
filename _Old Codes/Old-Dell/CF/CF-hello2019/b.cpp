#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e2 + 5;
int n = 0;
int a[MAXN];
int deg = 0, flag = 0;

inline void chang(int delta)
{
	deg += delta;
	while (deg < 0) deg += 360;
	while (deg >= 360) deg -= 360;
	return ;
}

void dfs(int ind, int dir)
{
	if (flag) return;
	if (ind == n)
	{
		if (!deg)
		{
			flag = 1;
		}
		return;
	}

	chang(dir * a[ind]);

	dfs(ind + 1, 1);
	dfs(ind + 1, -1);

	chang(- dir * a[ind]);

	return ;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	dfs(0, 1);

	if (flag) puts("YES");
	else puts("NO");

	return 0;
}