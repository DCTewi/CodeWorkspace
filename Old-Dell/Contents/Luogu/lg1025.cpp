#include <bits/stdc++.h>
using namespace std;

int n, k, ans = 0;
int now = 0;

void dfs(int last, int nowk)
{
	if (now > n && nowk > k) return;
	if (nowk == k)
	{
		if (now == n) ans++;
		return;
	}

	for (int i = last;now + i * (k - nowk) <= n; i++)
	{
		now += i;
		dfs(i, nowk + 1);
		now -= i;
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &n, &k);

	dfs(1, 0);

	printf("%d\n", ans);
	return 0;
}