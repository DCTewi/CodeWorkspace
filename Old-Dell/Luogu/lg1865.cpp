#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
const int MAXP = 1e6 + 5;
int n, m;
int prime[MAXP], top = 0;
int check[MAXN];

void getprime(int n)
{
	memset(check, 0, sizeof(check));
	check[0] = check[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (!check[i])
		{
			prime[top++] = i;
		}
		for (int j = 0; j < top; j++)
		{
			if (i * prime[j] > n) break;
			if (!check[prime[j] * i])
			{
				check[prime[j] * i] = 1;
			}
			if (i % prime[j] == 0) break;
		}
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &n, &m);
	getprime(m);
	while (n--)
	{
		int l, r; scanf("%d%d", &l, &r);
		if (l < 1 || l > m || r < 1 || r > m)
		{
			printf("Crossing the line\n");
			continue;
		}
		else 
		{
			int ans = 0;
			for (int i = 0; i < top; i++)
			{
				if (prime[i] < l) continue;
				if (prime[i] > r) break;
				ans++;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}