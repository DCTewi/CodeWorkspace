#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 5;
int n = 0, sum = 0, target = 0;
int a[MAXN];
int ans = 0;

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	target = sum / n;

	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] < target)
		{
			a[i + 1] -= target - a[i];
			ans++;
		}
		else if (a[i] > target)
		{
			a[i + 1] += a[i] - target;
			ans++;
		}
	}

	printf("%d\n", ans);

	return 0;
}