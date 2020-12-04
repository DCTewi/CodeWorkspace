#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int n;
int father[MAXN], son[MAXN];

inline int getfather(int n)
{
	if (father[n] == n) return n;
	father[n] = getfather(father[n]);
	return father[n];
}

inline void uni(int u, int v)
{
	father[getfather(u)] = getfather(v);
}

int main(int argc, char const *argv[])
{
	memset(son, 0, sizeof(son));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		father[i] = i;
	}
	for (int i = 1; i < n; i++)
	{
		int f, t; scanf("%d%d", &f, &t);
		if (f == 1 || t == 1) continue;
		else uni(f, t);
	}
	for (int i = 2; i <= n; i++)
	{
		son[getfather(i)]++;
	}
	int ans = 0;
	for (int i = 2; i <= n; i++)
	{
		ans = max(ans, son[i]);
	}
	printf("%d\n", ans);
	return 0;
}