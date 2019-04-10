#include <bits/stdc++.h>
using namespace std;

int n, k;
int now = 1;
int ans = 0;

int lowbit(int n)
{
	int ans = 0;
	for (; n & -n; n -= n & -n)
	{
		ans++;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &n, &k);

	if (n < k) return 0 * printf("%d\n", k - n);
	else while (lowbit(n) > k)
	{
		ans += n & -n;
		n += n & -n;
	}
	printf("%d\n", ans);

	return 0;
}