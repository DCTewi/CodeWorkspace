#include <bits/stdc++.h>
using namespace std;

const int MAXN = 70;
int n, cnt = 0;
int a[MAXN];
int tot = 0, maxlen = 0, minlen = 0x3ffffff;
int target;

void dfs(int res, int nowlen, int p)
{
	if (!res)
	{
		printf("%d\n", target);
		exit(0);
	}

	if (nowlen == target)
	{
		dfs(res - 1, 0, maxlen);
		return ;
	}
	for (int i = p; i >= minlen; i--)
	{
		if (a[i] && i + nowlen <= target)
		{
			a[i]--;
			dfs(res, nowlen + i, i);
			a[i]++;
			if (nowlen == 0 || nowlen + i == target) break;
		}
	}
	return ;
}

int main()
{
	scanf("%d", &n);
	while (n--)
	{
		int temp; scanf("%d", &temp);
		if (temp <= 50)
		{
			cnt++;
			a[temp]++;
			maxlen = max(maxlen, temp);
			minlen = min(minlen, temp);
			tot += temp;	
		}
	}

	int half = tot >> 1;
	for (int i = maxlen; i <= half; i++)
	{
		if (tot % i == 0)
		{
			target = i;
			dfs(tot / i, 0, maxlen);
		}
	}
	printf("%d\n", tot);

	return 0;
}
